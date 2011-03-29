// Copyright 2011 <Mark Washenberger>

#include "audio/SoundBuffer.h"

#include <stdlib.h>

namespace pg {
namespace audio {

SoundBuffer::SoundBuffer()
    : channels_(1), data_(NULL), frames_(0), size_(4096) {}
SoundBuffer::SoundBuffer(int size)
    : channels_(1), data_(NULL), frames_(0), size_(size) {}
SoundBuffer::~SoundBuffer() {
  delete data_;
}

int SoundBuffer::channels() { return channels_; }
int16_t *SoundBuffer::data() { return data_; }
int SoundBuffer::frames() { return frames_; }
int SoundBuffer::max_frames() { return size_ / channels_; }
int SoundBuffer::size() { return size_; }

void SoundBuffer::set_channels(int channels) { channels_ = channels; }
void SoundBuffer::set_frames(int frames) { frames_ = frames; }

void SoundBuffer::Init() {
  data_ = new int16_t[size_];
}

}  // namespace audio
}  // namespace pg
