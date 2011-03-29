// Copyright 2011 <Mark Washenberger>
#include "audio/FileInputStream.h"

namespace pg {
namespace audio {

FileInputStream::FileInputStream(const char *path)
    : path_(path), sound_file_(NULL), sound_file_info_(NULL) {}

void FileInputStream::Init() {
  sound_file_info_ = new SF_INFO;
  sound_file_info_->samplerate = 0;
  sound_file_info_->channels = 0;
  sound_file_info_->format = 0;
  sound_file_ = sf_open(path_, SFM_READ, sound_file_info_);
}

FileInputStream::~FileInputStream() {
  sf_close(sound_file_);
  delete sound_file_info_;
}

bool FileInputStream::Read(SoundBuffer *buffer) {
  buffer->set_channels(sound_file_info_->channels);
  int frames = sf_readf_short(sound_file_, buffer->data(),
                              buffer->max_frames());
  buffer->set_frames(frames);
  if (frames == 0)
    return false;
  return true;
}

}  // namespace audio
}  // namespace pg
