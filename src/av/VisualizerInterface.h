// Copyright 2011 <Mark Washenberger>

#ifndef SRC_AV_VISUALIZERINTERFACE_H_
#define SRC_AV_VISUALIZERINTERFACE_H_

#include "audio/SoundBuffer.h"
#include "video/ScreenInterface.h"

namespace pg {
namespace av {

class VisualizerInterface {
 public:
  virtual ~VisualizerInterface() {}

  virtual void Load(pg::audio::SoundBuffer *buffer) = 0;
  virtual void Visualize(pg::video::ScreenInterface *screen) = 0;
};

}  // namespace av
}  // namespace pg

#endif  // SRC_AV_VISUALIZERINTERFACE_H_
