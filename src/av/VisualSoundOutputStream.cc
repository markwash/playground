// Copyright 2011 <Mark Washenberger>

#include "av/VisualSoundOutputStream.h"

using pg::av::VisualizerInterface;
using pg::video::ScreenInterface;

namespace pg {
namespace av {

VisualSoundOutputStream::VisualSoundOutputStream(
    VisualizerInterface *visualizer, ScreenInterface *screen)
    : visualizer_(visualizer), screen_(screen) {}

VisualSoundOutputStream::~VisualSoundOutputStream() {
}

bool VisualSoundOutputStream::Write(pg::audio::SoundBuffer *buffer) {
  visualizer_->Visualize(buffer, screen_);
  return true;
}

}  // namespace av
}  // namespace pg
