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
  MockVisualizer(): buffer_(NULL), screen_(NULL) {}

  void Visualize(SoundBuffer *buffer, ScreenInterface *screen) {
    buffer_ = buffer;
    screen_ = screen;
  }

  SoundBuffer *buffer() { return buffer_; }
  ScreenInterface *screen() { return screen_; }

 private:
  SoundBuffer *buffer_;
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

  BOOST_CHECK_EQUAL(visualizer.buffer(), &buffer);
  BOOST_CHECK_EQUAL(visualizer.screen(), &screen);
}
