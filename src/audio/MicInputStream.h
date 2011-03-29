// Copyright 2010 <Mark Washenberger>

#include "audio/SoundInputStreamInterface.h"

#ifndef SRC_AUDIO_MICINPUTSTREAM_H_
#define SRC_AUDIO_MICINPUTSTREAM_H_

namespace pg {
namespace audio {

class MicInputStream: public SoundInputStreamInterface {
 public:
  void read(pg::audio::SoundBuffer *buffer) {}
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_MICINPUTSTREAM_H_
