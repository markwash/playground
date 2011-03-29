// Copyright 2011 <Mark Washenberger>

#ifndef SRC_AUDIO_FILEINPUTSTREAM_H_
#define SRC_AUDIO_FILEINPUTSTREAM_H_

#include "audio/SoundInputStreamInterface.h"

namespace pg {
namespace audio {

class FileInputStream: public pg::audio::SoundInputStreamInterface {
 public:
  explicit FileInputStream(const char *file);
  bool read(pg::audio::SoundBuffer *buffer) {return true;}
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_FILEINPUTSTREAM_H_
