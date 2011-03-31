// Copyright 2011 <Mark Washenberger>

#ifndef SRC_AV_TRANSFORMVISUALIZER_H_
#define SRC_AV_TRANSFORMVISUALIZER_H_

#include "audio/SoundTransformerInterface.h"
#include "av/VisualizerInterface.h"
#include "video/GrapherInterface.h"

namespace pg {
namespace av {

class TransformVisualizer: public pg::av::VisualizerInterface {
 public:
  TransformVisualizer(pg::audio::SoundTransformerInterface *transformer,
                      pg::video::GrapherInterface *grapher);

  void Visualize(pg::audio::SoundBuffer *buffer,
                 pg::video::ScreenInterface *screen);

 private:
  pg::audio::SoundTransformerInterface *transformer_;
  pg::video::GrapherInterface *grapher_;
};

}  // namespace av
}  // namespace pg

#endif  // SRC_AV_TRANSFORMVISUALIZER_H_
