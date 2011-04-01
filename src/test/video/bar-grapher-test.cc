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
  MockScreen(): clear_called_(false), draw_calls_(), commits_() {}

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

  bool clear_called() { return clear_called_; }
  vector<DrawCall> draw_calls() { return draw_calls_; }
  vector<vector<DrawCall> > commits() { return commits_; }

 private:
  bool clear_called_;
  vector<DrawCall> draw_calls_;
  vector<vector<DrawCall> > commits_;
};

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
  BOOST_CHECK_EQUAL(screen.commits().size(), 0);
}
