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
  visualizer_->Load(buffer);
  visualizer_->Visualize(screen_);
}

}  // namespace av
}  // namespace pg
