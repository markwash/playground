// Copyright 2011 <Mark Washenberger>
#include <stdlib.h>

#include "audio/FileInputStream.h"
#include "audio/FileOutputStream.h"
#include "audio/Pipe.h"

using pg::audio::FileInputStream;
using pg::audio::FileOutputStream;
using pg::audio::Pipe;

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FileInputStream in(argv[1]);
  in.Init();

  FileOutputStream out(argv[2]);
  out.Init();

  Pipe pipe(&in, &out);
  pipe.run_until_finished();

  return EXIT_SUCCESS;
}
