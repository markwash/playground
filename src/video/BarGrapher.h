// Copyright 2011 <Mark Washenberger>

#ifndef SRC_VIDEO_BARGRAPHER_H_
#define SRC_VIDEO_BARGRAPHER_H_

#include "video/GrapherInterface.h"

namespace pg {
namespace video {

class BarGrapher: public GrapherInterface {
 public:
  void Graph(pg::video::ScreenInterface *screen,
             const double *data, int data_size);
};

}  // namespace video
}  // namespace pg

#endif  // SRC_VIDEO_BARGRAPHER_H_
