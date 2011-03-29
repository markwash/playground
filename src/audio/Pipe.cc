// Copyright 2011 <Mark Washenberger>
#include "audio/Pipe.h"

namespace pg {
namespace audio {

Pipe::run_until_finished(void) {
  SoundBuffer buffer;
  while (1) {
    input->read(buffer);
    output->write(buffer);
  }
}

}  // namespace audio
}  // namespace pg
