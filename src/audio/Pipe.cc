// Copyright 2011 <Mark Washenberger>
#include "audio/Pipe.h"

namespace pg {
namespace audio {

void Pipe::run_until_finished(void) {
  SoundBuffer buffer;
  buffer.Init();
  while (1) {
    if (!input_->Read(&buffer))
      break;
    if (!output_->Write(&buffer))
      break;
  }
}

}  // namespace audio
}  // namespace pg
