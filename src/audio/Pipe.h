// Copyright 2010 <Mark Washenberger>

#ifndef SRC_AUDIO_PIPE_H_
#define SRC_AUDIO_PIPE_H_

#include "audio/SoundInputStreamInterface.h"
#include "audio/SoundOutputStreamInterface.h"

namespace pg {
namespace audio {

class Pipe {
 public:
  Pipe(pg::audio::SoundInputStreamInterface *input,
       pg::audio::SoundOutputStreamInterface *output)
      : input_(input), output_(output) {}

  void run_until_finished(void);
 private:
  pg::audio::SoundInputStreamInterface *input_;
  pg::audio::SoundOutputStreamInterface *output_;
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_PIPE_H_
