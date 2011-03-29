// Copyright 2010 <Mark Washenberger>
#include <stdlib.h>

#include "audio/FileOutputStream.h"
#include "audio/MicInputStream.h"
#include "audio/Pipe.h"
#include "audio/SoundInputStreamInterface.h"
#include "audio/SoundOutputStreamInterface.h"

using pg::audio::FileOutputStream;
using pg::audio::MicInputStream;
using pg::audio::Pipe;
using pg::audio::SoundInputStreamInterface;
using pg::audio::SoundOutputStreamInterface;

int main(int argc, char **argv) {
  // create input stream from mic input
  SoundInputStreamInterface *input;
  input = new MicInputStream();
  // create output stream that is sound file
  SoundOutputStreamInterface *output;
  output = new FileOutputStream();
  // create piping strategy
  Pipe *pipe = new Pipe(input, output);
  pipe->run_until_finished();

  delete input;
  delete output;
  delete pipe;

  return EXIT_SUCCESS;
}
