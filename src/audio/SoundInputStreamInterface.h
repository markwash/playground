// Copyright 2010 <Mark Washenberger>

#ifndef SRC_AUDIO_SOUNDINPUTSTREAMINTERFACE_H_
#define SRC_AUDIO_SOUNDINPUTSTREAMINTERFACE_H_

#include "audio/SoundBuffer.h"

namespace pg {
namespace audio {

class SoundInputStreamInterface {
 public:
  virtual bool Read(pg::audio::SoundBuffer *buffer) = 0;
  virtual ~SoundInputStreamInterface() {}
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_SOUNDINPUTSTREAMINTERFACE_H_
