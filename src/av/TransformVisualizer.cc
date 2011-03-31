// Copyright 2011 <Mark Washenberger>

#include "av/TransformVisualizer.h"

using pg::audio::SoundBuffer;
using pg::audio::SoundTransformerInterface;
using pg::video::GrapherInterface;
using pg::video::ScreenInterface;

namespace pg {
namespace av {

TransformVisualizer::TransformVisualizer(
    SoundTransformerInterface *transformer, GrapherInterface *grapher)
    : transformer_(transformer), grapher_(grapher) {}

void TransformVisualizer::Visualize(SoundBuffer *buffer,
                                    ScreenInterface *screen) {
  transformer_->Transform(buffer->data());
  grapher_->Graph(screen, transformer_->output(), transformer_->output_size());
}

}  // namespace av
}  // namespace pg
