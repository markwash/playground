// Copyright 2011 <Mark Washenberger>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE BarGrapherTest
#include <boost/test/unit_test.hpp>

#include <stdio.h>

#include <vector>

#include "video/BarGrapher.h"

using pg::video::BarGrapher;
using pg::video::Color;
using pg::video::GrapherInterface;
using pg::video::Rectangle;
using pg::video::ScreenInterface;

using std::vector;

class DrawCall {
 public:
  Rectangle rectangle;
  Color color;
};

class MockScreen: public ScreenInterface {
 public:
  MockScreen(): clear_called_(false) {}

  void Clear() {
    clear_called_ = true;
    draw_calls_.clear();
  }

  void Commit() {
    vector<DrawCall> commit = draw_calls_;
    commits_.push_back(commit);
  }

  void Draw(Rectangle rectangle, Color color) {
    DrawCall call;
    call.rectangle = rectangle;
    call.color = color;
    draw_calls_.push_back(call);
  }

  int width() const { return width_; }
  int height() const { return height_; }
  bool clear_called() { return clear_called_; }
  vector<DrawCall> draw_calls() { return draw_calls_; }
  vector<vector<DrawCall> > commits() { return commits_; }

  void set_width(int width) { width_ = width; }
  void set_height(int height) { height_ = height; }

 private:
  int width_;
  int height_;
  bool clear_called_;
  vector<DrawCall> draw_calls_;
  vector<vector<DrawCall> > commits_;
};

static bool Equal(Rectangle left, Rectangle right) {
  return left.start_x == right.start_x
      && left.end_x == right.end_x
      && left.start_y == right.start_y
      && left.end_y == right.end_y;
}

static bool Equal(Color left, Color right) {
  return left.red == right.red
      && left.green == right.green
      && left.blue == right.blue;
}

static bool Contains(vector<DrawCall> list, Rectangle rectangle, Color color) {
  for (int i = 0; i < list.size(); i++) {
    if (Equal(list[i].rectangle, rectangle)
        && Equal(list[i].color, color))
      return true;
  }
  return false;
}

static void Display(vector<DrawCall> list) {
  Rectangle rectangle;
  Color color;
  for (int i = 0; i < list.size(); i++) {
    rectangle = list[i].rectangle;
    color = list[i].color;
    fprintf(stderr, "[x = (%d, %d), y = (%d, %d)], {%d, %d, %d}\n",
            rectangle.start_x, rectangle.end_x,
            rectangle.start_y, rectangle.end_y,
            color.red, color.green, color.blue);
  }
}

struct F {
  F(): screen(), bar_grapher(), grapher(&bar_grapher) {}
  MockScreen screen;
  BarGrapher bar_grapher;
  GrapherInterface *grapher;
};

BOOST_FIXTURE_TEST_CASE(test_no_data, F) {
  grapher->Graph(&screen, NULL, 0);
  BOOST_CHECK(screen.clear_called());
  BOOST_CHECK_EQUAL(screen.draw_calls().size(), 0);
  BOOST_CHECK_EQUAL(screen.commits().size(), 1);
}

BOOST_FIXTURE_TEST_CASE(test_single_point, F) {
  double datum = 1.0;
  screen.set_width(10);
  screen.set_height(20);
  grapher->Graph(&screen, &datum, 1);
  BOOST_CHECK(screen.clear_called());
  BOOST_REQUIRE_EQUAL(screen.commits().size(), 1);
  BOOST_REQUIRE_EQUAL(screen.commits()[0].size(), 1);
  DrawCall call = screen.commits()[0][0];
  Rectangle expected_rectangle = {1, 1, 8, 18};
  Color red = {255, 0, 0};
  BOOST_CHECK(Equal(call.rectangle, expected_rectangle));
  BOOST_CHECK(Equal(call.color, red));
}

BOOST_FIXTURE_TEST_CASE(test_three_points, F) {
  double data[] = {0.0, 0.5, 1.0};
  screen.set_width(16);
  screen.set_height(102);
  grapher->Graph(&screen, data, 3);
  vector<DrawCall> commit = screen.commits()[0];
  Color red = {255, 0, 0};
  Color blue = {0, 0, 255};
  Color purple = {127, 0, 127};
  Rectangle left = {1, 81, 4, 100};
  Rectangle middle = {6, 40, 9, 100};
  Rectangle right = {11, 1, 15, 100};
  BOOST_CHECK(Contains(commit, left, blue));
  BOOST_CHECK(Contains(commit, right, red));
  BOOST_CHECK(Contains(commit, middle, purple));
}
