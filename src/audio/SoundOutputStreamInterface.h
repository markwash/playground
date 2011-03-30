// Copyright 2010 <Mark Washenberger>
#ifndef SRC_AUDIO_SOUNDOUTPUTSTREAMINTERFACE_H_
#define SRC_AUDIO_SOUNDOUTPUTSTREAMINTERFACE_H_

#include "audio/SoundBuffer.h"

namespace pg {
namespace audio {

class SoundOutputStreamInterface {
 public:
  virtual bool Write(pg::audio::SoundBuffer *buffer) = 0;
  virtual ~SoundOutputStreamInterface() {}
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_SOUNDOUTPUTSTREAMINTERFACE_H_
