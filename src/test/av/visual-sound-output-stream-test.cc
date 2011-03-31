// Copyright 2011 <Mark Washenberger>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE VisualSoundOutputStreamTest
#include <boost/test/unit_test.hpp>

#include "av/VisualSoundOutputStream.h"
#include "av/VisualizerInterface.h"
#include "video/ScreenInterface.h"

using pg::audio::SoundBuffer;
using pg::audio::SoundOutputStreamInterface;
using pg::av::VisualizerInterface;
using pg::av::VisualSoundOutputStream;
using pg::video::ScreenInterface;

class MockVisualizer: public VisualizerInterface {
 public:
  MockVisualizer(): load_called_(false), screen_(NULL) {}

  void Load(SoundBuffer *buffer) {
    load_called_ = true;
  }

  void Visualize(ScreenInterface *screen) {
    screen_ = screen;
  }

  bool load_called() { return load_called_; }
  ScreenInterface *screen() { return screen_; }

 private:
  bool load_called_;
  ScreenInterface *screen_;
};

class MockScreen: public pg::video::ScreenInterface {
};

struct F {
  F() {}
};

BOOST_FIXTURE_TEST_CASE(test_create_and_write, F) {
  MockVisualizer visualizer;
  MockScreen screen;
  VisualSoundOutputStream visual_output(&visualizer, &screen);
  SoundOutputStreamInterface *output = &visual_output;

  SoundBuffer buffer(4096);
  buffer.Init();
  buffer.set_frames(1024);

  output->Write(&buffer);

  BOOST_CHECK(visualizer.load_called());
  BOOST_CHECK_EQUAL(visualizer.screen(), &screen);
}
