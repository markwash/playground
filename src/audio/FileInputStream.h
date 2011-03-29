// Copyright 2011 <Mark Washenberger>

#ifndef SRC_AUDIO_FILEINPUTSTREAM_H_
#define SRC_AUDIO_FILEINPUTSTREAM_H_

#include <sndfile.h>

#include "audio/SoundInputStreamInterface.h"

namespace pg {
namespace audio {

class FileInputStream: public pg::audio::SoundInputStreamInterface {
 public:
  explicit FileInputStream(const char *path);
  ~FileInputStream();
  void Init();
  bool Read(pg::audio::SoundBuffer *buffer);

 private:
  const char *path_;
  SNDFILE *sound_file_;
  SF_INFO *sound_file_info_;
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_FILEINPUTSTREAM_H_
