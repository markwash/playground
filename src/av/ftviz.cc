// Copyright 2010 <Mark Washenberger>
#include <stdlib.h>

#include "audio/MicInputStream.h"

using pg::audio::SoundInputStreamInterface;
using pg::audio::MicInputStream;

int main(int argc, char **argv) {
  // create input stream from mic input
  SoundInputStreamInterface *input;
  input = new MicInputStream();
  // create output stream that is actually video
  // create null timer
  // create TimedAudioPipe pipe
  // pipe.run_until_done

  delete input;

  return EXIT_SUCCESS;
}
