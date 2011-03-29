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
}
