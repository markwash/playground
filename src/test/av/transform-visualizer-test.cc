// Copyright 2011 <Mark Washenberger>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TransformVisualizerTest
#include <boost/test/unit_test.hpp>

#include <vector>

#include "av/TransformVisualizer.h"
#include "video/ScreenInterface.h"

using pg::audio::SoundTransformerInterface;
using pg::av::TransformVisualizer;
using pg::av::VisualizerInterface;
using pg::video::GrapherInterface;
using pg::audio::SoundBuffer;
using pg::video::ScreenInterface;

class MockScreen: public pg::video::ScreenInterface {
  void Clear() {}
  void Update() {}
  void Draw(pg::video::Rectangle rectangle, pg::video::Color color) {}
};

class GraphCall {
 public:
  ScreenInterface *screen;
  const double *data;
  int data_size;
};

class MockGrapher: public GrapherInterface {
 public:

  void Graph(ScreenInterface *screen, const double *data, int data_size) {
    GraphCall call;
    call.screen = screen;
    call.data = data;
    call.data_size = data_size;
    calls_.push_back(call);
  }

  std::vector<GraphCall> calls() { return calls_; }

 private:
  std::vector<GraphCall> calls_;
};

class MockSoundTransformer: public SoundTransformerInterface {
 public:
  MockSoundTransformer(int input_size, int output_size)
      : input_size_(input_size), output_size_(output_size),
      transform_count_(0), output_(NULL) {}

  void Transform(int16_t *input) {
    transform_count_++;
  }

  void set_input_size(int size) { input_size_ = size; }
  void set_output_size(int size) { output_size_ = size; }
  void set_output(const double *output) { output_ = output; }

  int input_size() const { return input_size_; }
  int output_size() const { return output_size_; }
  const double *output() const { return output_; }
  int transform_count() const { return transform_count_; }

 private:
  int input_size_;
  int output_size_;
  int transform_count_;
  const double *output_;
};

struct F {
  F()
      : transformer(1024, 1024), grapher(), screen(),
      transform_visualizer(&transformer, &grapher),
      visualizer(&transform_visualizer),
      buffer(4096) {
    buffer.Init();
    buffer.set_channels(1);
  }
  MockSoundTransformer transformer;
  MockGrapher grapher;
  MockScreen screen;
  TransformVisualizer transform_visualizer;
  VisualizerInterface *visualizer;
  SoundBuffer buffer;
};

BOOST_FIXTURE_TEST_CASE(test_visualize_basic, F) {
  buffer.set_frames(1024);
  visualizer->Visualize(&buffer, &screen);

  BOOST_CHECK_EQUAL(transformer.transform_count(), 1);
  BOOST_REQUIRE_EQUAL(grapher.calls().size(), 1);

  GraphCall call = grapher.calls()[0];
  BOOST_CHECK_EQUAL(call.screen, &screen);
  BOOST_CHECK(call.data == NULL);
  BOOST_CHECK_EQUAL(call.data_size, 1024);
}

BOOST_FIXTURE_TEST_CASE(test_visualize_waits_for_full_buffer, F) {
  buffer.set_frames(512);
  visualizer->Visualize(&buffer, &screen);

  BOOST_CHECK_EQUAL(transformer.transform_count(), 0);
  BOOST_CHECK_EQUAL(grapher.calls().size(), 0);
}

BOOST_FIXTURE_TEST_CASE(test_visualize_buffers_input, F) {
  buffer.set_frames(512);
  visualizer->Visualize(&buffer, &screen);
  visualizer->Visualize(&buffer, &screen);

  BOOST_CHECK_EQUAL(transformer.transform_count(), 1);
  BOOST_REQUIRE_EQUAL(grapher.calls().size(), 1);

  GraphCall call = grapher.calls()[0];
  BOOST_CHECK_EQUAL(call.screen, &screen);
  BOOST_CHECK(call.data == NULL);
  BOOST_CHECK_EQUAL(call.data_size, 1024);
}

BOOST_FIXTURE_TEST_CASE(test_visualize_saves_overflow, F) {
  buffer.set_frames(700);
  visualizer->Visualize(&buffer, &screen);
  visualizer->Visualize(&buffer, &screen);
  visualizer->Visualize(&buffer, &screen);

  BOOST_CHECK_EQUAL(transformer.transform_count(), 2);
  BOOST_CHECK_EQUAL(grapher.calls().size(), 2);
}

BOOST_FIXTURE_TEST_CASE(test_visualize_gives_graph_correct_data, F) {
  buffer.set_frames(1024);
  double dummy_output;
  transformer.set_output(&dummy_output);
  visualizer->Visualize(&buffer, &screen);
  BOOST_CHECK_EQUAL(grapher.calls()[0].data, &dummy_output);
}
