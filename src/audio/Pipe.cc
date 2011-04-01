// Copyright 2011 <Mark Washenberger>
#include "audio/Pipe.h"

using pg::audio::SoundInputStreamInterface;
using pg::audio::SoundOutputStreamInterface;

namespace pg {
namespace audio {

class NeverStop: public pg::audio::PipeStopCondition {
 public:
  bool IsTimeToStop() { return false; }
};

static NeverStop never_stop;

Pipe::Pipe(SoundInputStreamInterface *input,
           SoundOutputStreamInterface *output)
    : input_(input), output_(output), stop_condition_(&never_stop) {}

Pipe::Pipe(SoundInputStreamInterface *input,
           SoundOutputStreamInterface *output,
           PipeStopCondition *stop_condition)
    : input_(input), output_(output), stop_condition_(stop_condition) {}

void Pipe::run_until_finished(void) {
  SoundBuffer buffer;
  buffer.Init();
  while (!stop_condition_->IsTimeToStop()) {
    if (!input_->Read(&buffer))
      break;
    if (!output_->Write(&buffer))
      break;
  }
}

}  // namespace audio
}  // namespace pg
