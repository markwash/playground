// Copyright 2011 <Mark Washenberger>

#ifndef SRC_VIDEO_BARGRAPHER_H_
#define SRC_VIDEO_BARGRAPHER_H_

#include "video/GrapherInterface.h"

namespace pg {
namespace video {

class BarGrapher: public GrapherInterface {
 public:
  BarGrapher();
  void Graph(pg::video::ScreenInterface *screen,
             const double *data, int data_size);
 private:
  double FindMax(const double *data, int data_size);
  double FindMin(const double *data, int data_size);
  void UpdateMax(double max);
  void UpdateMin(double min);
  void DrawBar(ScreenInterface *screen, double data, int bar, int bars);
  pg::video::Color CalculateColor(double data);
  pg::video::Rectangle CalculateRectangle(ScreenInterface *screen,
                                          double data, int bar, int bars);
  void CalculateStartAndEndX(int width, int bar, int bars,
                             pg::video::Rectangle *rectangle);
  void CalculateStartAndEndY(int height, double data,
                             pg::video::Rectangle *rectangle);

  double max_;
  double min_;
};

}  // namespace video
}  // namespace pg

#endif  // SRC_VIDEO_BARGRAPHER_H_
