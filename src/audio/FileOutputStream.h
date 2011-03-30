// Copyright 2010 <Mark Washenberger>

#ifndef SRC_AUDIO_FILEOUTPUTSTREAM_H_
#define SRC_AUDIO_FILEOUTPUTSTREAM_H_

#include <sndfile.h>

#include "audio/SoundOutputStreamInterface.h"

namespace pg {
namespace audio {

class FileOutputStream: public pg::audio::SoundOutputStreamInterface {
 public:
  explicit FileOutputStream(const char *path);
  ~FileOutputStream();
  void Init();
  bool Write(pg::audio::SoundBuffer *buffer);

 private:
  const char *path_;
  SNDFILE *sound_file_;
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_FILEOUTPUTSTREAM_H_
