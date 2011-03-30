// Copyright 2011 <Mark Washenberger>

#include "audio/FileOutputStream.h"

namespace pg {
namespace audio {

FileOutputStream::FileOutputStream(const char *path)
    : path_(path), sound_file_(NULL) {}

void FileOutputStream::Init() {
  SF_INFO info;
  info.samplerate = 44100;
  info.channels = 1;
  info.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
  sound_file_ = sf_open(path_, SFM_WRITE, &info);
}

FileOutputStream::~FileOutputStream() {
  sf_close(sound_file_);
}

bool FileOutputStream::Write(pg::audio::SoundBuffer *buffer) {
  sf_writef_short(sound_file_, buffer->data(), buffer->frames());
  return true;
}

}  // namespace audio
}  // namespace pg
