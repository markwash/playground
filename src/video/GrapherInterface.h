// Copyright 2011 <Mark Washenberger>

#ifndef SRC_VIDEO_GRAPHERINTERFACE_H_
#define SRC_VIDEO_GRAPHERINTERFACE_H_

#include "video/ScreenInterface.h"

namespace pg {
namespace video {

class GrapherInterface {
 public:
  virtual ~GrapherInterface() {}
  virtual void Graph(pg::video::ScreenInterface *screen,
             const double *data, int data_size) = 0;
};

}  // namespace video
}  // namespace pg

#endif  // SRC_VIDEO_GRAPHERINTERFACE_H_
