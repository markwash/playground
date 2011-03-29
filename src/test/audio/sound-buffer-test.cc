// Copyright 2011 <Mark Washenberger>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SoundBufferTest
#include <boost/test/unit_test.hpp>

#include "audio/SoundBuffer.h"

using pg::audio::SoundBuffer;

struct F {
  F() {}
};

BOOST_FIXTURE_TEST_CASE(test_create, F) {
  SoundBuffer buf;
  BOOST_CHECK_EQUAL(buf.size(), 4096);
}

BOOST_FIXTURE_TEST_CASE(test_create_with_size, F) {
  SoundBuffer buf(9000);
  BOOST_CHECK_EQUAL(buf.size(), 9000);
}

BOOST_FIXTURE_TEST_CASE(test_set_channels, F) {
  SoundBuffer buf;
  BOOST_CHECK_EQUAL(buf.channels(), 1);
  buf.set_channels(2);
  BOOST_CHECK_EQUAL(buf.channels(), 2);
}

BOOST_FIXTURE_TEST_CASE(test_max_frames, F) {
  SoundBuffer buf(10000);
  buf.set_channels(3);
  BOOST_CHECK_EQUAL(buf.max_frames(), 3333);
}

BOOST_FIXTURE_TEST_CASE(test_data, F) {
  SoundBuffer buf;
  BOOST_CHECK(buf.data() == NULL);
  buf.Init();
  BOOST_CHECK(buf.data() != NULL);
}

BOOST_FIXTURE_TEST_CASE(test_default_frames, F) {
  SoundBuffer buf;
  BOOST_CHECK_EQUAL(buf.frames(), 0);
}

BOOST_FIXTURE_TEST_CASE(test_set_frames, F) {
  SoundBuffer buf;
  buf.set_frames(1000);
  BOOST_CHECK_EQUAL(buf.frames(), 1000);
}
