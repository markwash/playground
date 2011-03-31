// Copyright 2011 <Mark Washenberger>

#ifndef SRC_AV_VISUALSOUNDOUTPUTSTREAM_H_
#define SRC_AV_VISUALSOUNDOUTPUTSTREAM_H_

#include "audio/SoundOutputStreamInterface.h"
#include "av/VisualizerInterface.h"
#include "video/ScreenInterface.h"

namespace pg {
namespace av {

class VisualSoundOutputStream: public pg::audio::SoundOutputStreamInterface {
 public:
  VisualSoundOutputStream(pg::av::VisualizerInterface *visualizer,
                         pg::video::ScreenInterface *screen);
  ~VisualSoundOutputStream();

  bool Write(pg::audio::SoundBuffer *buffer);

 private:
  pg::av::VisualizerInterface *visualizer_;
  pg::video::ScreenInterface *screen_;
};

}  // namespace av
}  // namespace pg

#endif  // SRC_AV_VISUALSOUNDOUTPUTSTREAM_H_
