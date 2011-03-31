// Copyright 2011 <Mark Washenberger>

#ifndef SRC_AV_VISUALSOUNDOUTPUTSTREAM_H_
#define SRC_AV_VISUALSOUNDOUTPUTSTREAM_H_

#include "av/VisualizerInterface.h"
#include "video/ScreenInterface.h"

namespace pg {
namespace av {

class VisualSoundOutputStream {
 public:
  VisualSoundOutputStream(pg::av::VisualizerInterface *visualizer,
                         pg::video::ScreenInterface *screen);
};

}  // namespace av
}  // namespace pg

#endif  // SRC_AV_VISUALSOUNDOUTPUTSTREAM_H_
