// Copyright 2011 <Mark Washenberger>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FileInputStreamTest
#include <boost/test/unit_test.hpp>

#include "audio/FileInputStream.h"

using pg::audio::FileInputStream;
using pg::audio::SoundBuffer;
using pg::audio::SoundInputStreamInterface;

struct F {
  F() {}
};

BOOST_FIXTURE_TEST_CASE(test_create_and_read, F) {
  SoundInputStreamInterface *file = new FileInputStream("test.wav");
  SoundBuffer buf;
  while (file->read(&buf)) {
    break;
  }
  delete file;
}
