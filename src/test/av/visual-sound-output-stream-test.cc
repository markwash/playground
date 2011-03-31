// Copyright 2011 <Mark Washenberger>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE VisualSoundOutputStreamTest
#include <boost/test/unit_test.hpp>

#include "av/VisualSoundOutputStream.h"
#include "av/VisualizerInterface.h"
#include "video/ScreenInterface.h"

using pg::av::VisualizerInterface;
using pg::av::VisualSoundOutputStream;
using pg::video::ScreenInterface;

class MockVisualizer: public VisualizerInterface {
};

class MockScreen: public pg::video::ScreenInterface {
};

struct F {
  F() {}
};

BOOST_FIXTURE_TEST_CASE(test_create, F) {
  MockVisualizer visualizer;
  MockScreen screen;
  VisualSoundOutputStream output(&visualizer, &screen);
}
