// Copyright 2011 <Mark Washenberger>

#include "video/BarGrapher.h"

using pg::video::ScreenInterface;

namespace pg {
namespace video {

void BarGrapher::Graph(ScreenInterface *screen,
                       const double *data, int data_size) {
  screen->Clear();
}

}  // namespace video
}  // namespace pg
