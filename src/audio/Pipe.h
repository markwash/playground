// Copyright 2010 <Mark Washenberger>

#ifndef SRC_AUDIO_PIPE_H_
#define SRC_AUDIO_PIPE_H_

#include "audio/SoundInputStreamInterface.h"
#include "audio/SoundOutputStreamInterface.h"

namespace pg {
namespace audio {

class PipeStopCondition {
 public:
  virtual ~PipeStopCondition() {}
  virtual bool IsTimeToStop() = 0;
};

class Pipe {
 public:
  Pipe(pg::audio::SoundInputStreamInterface *input,
       pg::audio::SoundOutputStreamInterface *output);

  Pipe(pg::audio::SoundInputStreamInterface *input,
       pg::audio::SoundOutputStreamInterface *output,
       PipeStopCondition *stop_condition);

  void run_until_finished(void);
 private:
  pg::audio::SoundInputStreamInterface *input_;
  pg::audio::SoundOutputStreamInterface *output_;
  PipeStopCondition *stop_condition_;
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_PIPE_H_
