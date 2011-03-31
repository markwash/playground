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
  void EnsureInternalBufferIsLargeEnough();
  int ConsumeFrames(pg::audio::SoundBuffer *buffer,
                    int already_consumed_frames);
  int CalculateFramesToCopy(int remaining_frames);
  bool WouldOverfillBuffer(int frames);
  int EnoughToFillBuffer();
  void CopyFrames(pg::audio::SoundBuffer *input, int frames_to_copy,
                  int already_consumed_frames);
  bool IsReadyToTransform();
  void TransformAndGraph(pg::video::ScreenInterface *screen);

  pg::audio::SoundTransformerInterface *transformer_;
  pg::video::GrapherInterface *grapher_;
  int16_t *buffer_;
  int buffer_current_size_;
  int buffer_max_size_;
};

}  // namespace av
}  // namespace pg

#endif  // SRC_AV_TRANSFORMVISUALIZER_H_
