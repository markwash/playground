// Copyright 2010 <Mark Washenberger>
#include <stdlib.h>

#include "audio/MicInputStream.h"
#include "audio/SoundInputStreamInterface.h"
#include "audio/SoundOutputStreamInterface.h"
#include "video/FtVisualOutputStream.h"

using pg::audio::MicInputStream;
using pg::audio::SoundInputStreamInterface;
using pg::audio::SoundOutputStreamInterface;
using pg::video::FtVisualOutputStream;

int main(int argc, char **argv) {
  // create input stream from mic input
  SoundInputStreamInterface *input;
  input = new MicInputStream();
  // create output stream that is actually video
  SoundOutputStreamInterface *output;
  output = new FtVisualOutputStream();
  // create null timer
  // create TimedAudioPipe pipe
  // pipe.run_until_done

  delete input;

  return EXIT_SUCCESS;
}
