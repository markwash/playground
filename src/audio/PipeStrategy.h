// Copyright 2010 <Mark Washenberger>

#ifndef SRC_AUDIO_PIPESTRATEGY_H_
#define SRC_AUDIO_PIPESTRATEGY_H_

#include "audio/SoundInputStreamInterface.h"
#include "audio/SoundOutputStreamInterface.h"

using pg::audio::SoundInputStreamInterface;
using pg::audio::SoundOutputStreamInterface;

namespace pg {
namespace audio {

class PipeStrategy {
 public:
  PipeStrategy(SoundInputStreamInterface *input,
               SoundOutputStreamInterface *output) {}

  void run_until_finished(void) {}
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_PIPESTRATEGY_H_
