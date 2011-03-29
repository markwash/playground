// Copyright 2010 <Mark Washenberger>

#include "audio/SoundInputStreamInterface.h"

#ifndef SRC_AUDIO_MICINPUTSTREAM_H_
#define SRC_AUDIO_MICINPUTSTREAM_H_

namespace pg {
namespace audio {

class MicInputStream: public SoundInputStreamInterface {
 public:
  bool Read(pg::audio::SoundBuffer *buffer) {return true;}
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_MICINPUTSTREAM_H_
