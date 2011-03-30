// Copyright 2010 <Mark Washenberger>

#ifndef SRC_AUDIO_PIPE_H_
#define SRC_AUDIO_PIPE_H_

#include "audio/SoundInputStreamInterface.h"
#include "audio/SoundOutputStreamInterface.h"

using pg::audio::SoundInputStreamInterface;
using pg::audio::SoundOutputStreamInterface;

namespace pg {
namespace audio {

class Pipe {
 public:
  Pipe(SoundInputStreamInterface *input,
       SoundOutputStreamInterface *output)
      : input_(input), output_(output) {}

  void run_until_finished(void);
 private:
  SoundInputStreamInterface *input_;
  SoundOutputStreamInterface *output_;
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_PIPE_H_
