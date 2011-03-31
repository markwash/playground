// Copyright 2011 <Mark Washenberger>

#include "av/TransformVisualizer.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

using pg::audio::SoundBuffer;
using pg::audio::SoundTransformerInterface;
using pg::video::GrapherInterface;
using pg::video::ScreenInterface;

namespace pg {
namespace av {

TransformVisualizer::TransformVisualizer(
    SoundTransformerInterface *transformer, GrapherInterface *grapher)
    : transformer_(transformer), grapher_(grapher),
    buffer_(NULL), buffer_current_size_(0), buffer_max_size_(0) {}

void TransformVisualizer::Visualize(SoundBuffer *buffer,
                                    ScreenInterface *screen) {
  EnsureInternalBufferIsLargeEnough();
  int consumed_frames = 0;
  while (consumed_frames < buffer->frames()) {
    consumed_frames += ConsumeFrames(buffer, consumed_frames);
    if (IsReadyToTransform())
      TransformAndGraph(screen);
  }
}

void TransformVisualizer::EnsureInternalBufferIsLargeEnough() {
  if (buffer_max_size_ < transformer_->input_size()) {
    buffer_max_size_ = transformer_->input_size();
    buffer_ = static_cast<int16_t *>(
        realloc(buffer_, buffer_max_size_ * sizeof(int16_t)));
  }
}

int TransformVisualizer::ConsumeFrames(SoundBuffer *buffer,
                                       int already_consumed_frames) {
  int remaining_frames = buffer->frames() - already_consumed_frames;
  int frames = CalculateFramesToCopy(remaining_frames);
  CopyFrames(buffer, frames, already_consumed_frames);
  return frames;
}

int TransformVisualizer::CalculateFramesToCopy(int remaining_frames) {
  if (WouldOverfillBuffer(remaining_frames))
    return EnoughToFillBuffer();
  else
    return remaining_frames;
}

bool TransformVisualizer::WouldOverfillBuffer(int frames) {
  return frames + buffer_current_size_ > transformer_->input_size();
}

int TransformVisualizer::EnoughToFillBuffer() {
  return transformer_->input_size() - buffer_current_size_;
}

void TransformVisualizer::CopyFrames(SoundBuffer *input, int frames_to_copy,
                                     int already_consumed_frames) {
  memcpy(buffer_ + buffer_current_size_,
         input->data() + already_consumed_frames,
         frames_to_copy * sizeof(int16_t));
  buffer_current_size_ += frames_to_copy;
}

bool TransformVisualizer::IsReadyToTransform() {
  return buffer_current_size_ >= transformer_->input_size();
}

void TransformVisualizer::TransformAndGraph(ScreenInterface *screen) {
  transformer_->Transform(buffer_);
  buffer_current_size_ = 0;
  grapher_->Graph(screen, transformer_->output(), transformer_->output_size());
}

}  // namespace av
}  // namespace pg
