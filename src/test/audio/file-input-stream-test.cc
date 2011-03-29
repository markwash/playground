// Copyright 2011 <Mark Washenberger>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FileInputStreamTest
#include <boost/test/unit_test.hpp>

#include "audio/FileInputStream.h"

using pg::audio::FileInputStream;
using pg::audio::SoundInputStreamInterface;

struct F {
  F() {}
};

BOOST_FIXTURE_TEST_CASE(test, F) {
  SoundInputStreamInterface *file = new FileInputStream();
  delete file;
}
