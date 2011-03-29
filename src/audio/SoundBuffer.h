// Copyright 2011 <Mark Washenberger>

#ifndef SRC_AUDIO_SOUNDBUFFER_H_
#define SRC_AUDIO_SOUNDBUFFER_H_

#include <stdint.h>

namespace pg {
namespace audio {

class SoundBuffer {
 public:
  SoundBuffer();
  explicit SoundBuffer(int size);
  ~SoundBuffer();

  void Init();

  int channels();
  int16_t *data();
  int frames();
  int max_frames();
  int size();

  void set_channels(int channels);
  void set_frames(int frames);

 private:
  int channels_;
  int frames_;
  int size_;
  int16_t *data_;
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_SOUNDBUFFER_H_
