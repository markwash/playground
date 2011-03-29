// Copyright 2011 <Mark Washenberger>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FileInputStreamTest
#include <boost/test/unit_test.hpp>

#include <stdio.h>
#include <sndfile.h>

#include "audio/FileInputStream.h"

using pg::audio::FileInputStream;
using pg::audio::SoundBuffer;
using pg::audio::SoundInputStreamInterface;

struct F {
  F() {}
};

BOOST_FIXTURE_TEST_CASE(test_create_and_read, F) {
  FileInputStream *file = new FileInputStream("test.wav");
  file->Init();
  SoundInputStreamInterface *input_stream = file;
  SoundBuffer buf;
  buf.Init();
  while (input_stream->Read(&buf))
    BOOST_CHECK(buf.frames() > 0);
  BOOST_CHECK_EQUAL(buf.frames(), 0);
  delete input_stream;
}
