// Copyright 2011 <Mark Washenberger>

#include "video/BarGrapher.h"

using pg::video::ScreenInterface;

namespace pg {
namespace video {

void BarGrapher::Graph(ScreenInterface *screen,
                       const double *data, int data_size) {
  screen->Clear();
  if (data_size <= 0)
    return;
  Rectangle rectangle = {0, 0, screen->width() - 1, screen->height() - 1};
  Color color = {0, 0, 0};
  screen->Draw(rectangle, color);
  screen->Commit();
}

}  // namespace video
}  // namespace pg
