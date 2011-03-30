// Copyright 2011 <Mark Washenberger>

#include <portaudiocpp/BlockingStream.hxx>

#include "audio/SoundInputStreamInterface.h"

#ifndef SRC_AUDIO_MICINPUTSTREAM_H_
#define SRC_AUDIO_MICINPUTSTREAM_H_

namespace pg {
namespace audio {

class MicInputStream: public SoundInputStreamInterface {
 public:
  MicInputStream();
  ~MicInputStream();

  void Init();
  bool Read(pg::audio::SoundBuffer *buffer);

 private:
  portaudio::BlockingStream *input_;
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_MICINPUTSTREAM_H_
