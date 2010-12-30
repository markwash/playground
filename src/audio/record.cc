// Copyright 2010 <Mark Washenberger>
#include <stdlib.h>

#include "audio/FileOutputStream.h"
#include "audio/MicInputStream.h"
#include "audio/SoundInputStreamInterface.h"
#include "audio/SoundOutputStreamInterface.h"

using pg::audio::FileOutputStream;
using pg::audio::MicInputStream;
using pg::audio::SoundInputStreamInterface;
using pg::audio::SoundOutputStreamInterface;

int main(int argc, char **argv) {
  // create input stream from mic input
  SoundInputStreamInterface *input;
  input = new MicInputStream();
  // create output stream that is sound file
  SoundOutputStreamInterface *output;
  output = new FileOutputStream();
  // create null timer
  // create TimedAudioPipe pipe
  // pipe.run_until_done

  delete input;
  delete output;

  return EXIT_SUCCESS;
}
