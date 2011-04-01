// Copyright 2011 <Mark Washenberger>

#include "video/BarGrapher.h"

using pg::video::Color;
using pg::video::Rectangle;
using pg::video::ScreenInterface;

namespace pg {
namespace video {

BarGrapher::BarGrapher(): max_(0.0), min_(0.0) {}

void BarGrapher::Graph(ScreenInterface *screen,
                       const double *data, int data_size) {
  screen->Clear();
  UpdateMax(FindMax(data, data_size));
  UpdateMin(FindMin(data, data_size));
  for (int i = 0; i < data_size; i++)
    DrawBar(screen, data[i], i, data_size);
  screen->Commit();
}

double BarGrapher::FindMax(const double *data, int data_size) {
  double max = 0.0;
  for (int i = 0; i < data_size; i++) {
    if (data[i] > max)
      max = data[i];
  }
  return max;
}

double BarGrapher::FindMin(const double *data, int data_size) {
  if (data_size <= 0)
    return 0.0;
  double min = data[0];
  for (int i = 1; i < data_size; i++) {
    if (data[i] < min)
      min = data[i];
  }
  return min;
}

void BarGrapher::UpdateMax(double max) {
  max_ = max_ - 0.005 * (max_ - min_);
  if (max > max_)
    max_ = max;
}

void BarGrapher::UpdateMin(double min) {
  min_ = min_ + 0.005 * (max_ - min_);
  if (min < min_)
    min_ = min;
}

void BarGrapher::DrawBar(ScreenInterface *screen,
                         double data, int bar, int bars) {
  Color color = CalculateColor(data);
  Rectangle rectangle = CalculateRectangle(screen, data, bar, bars);
  screen->Draw(rectangle, color);
}

Color BarGrapher::CalculateColor(double data) {
  Color color;
  double portion;
  if (max_ <= min_)
    portion = 0.0;
  else
    portion = (data - min_) / (max_ - min_);
  color.red = 255 * portion;
  color.green = 0;
  color.blue = 255 - 255 * portion;
  return color;
}

Rectangle BarGrapher::CalculateRectangle(ScreenInterface *screen,
                                         double data, int bar, int bars) {
  Rectangle rectangle;
  CalculateStartAndEndX(screen->width(), bar, bars, &rectangle);
  CalculateStartAndEndY(screen->height(), data, &rectangle);
  return rectangle;
}

void BarGrapher::CalculateStartAndEndX(int width, int bar, int bars,
                                       Rectangle *rectangle) {
  int bar_width = (width - 1) / bars;
  int used_width = bar_width * bars;
  int total_margin = width - used_width;
  int left_margin = total_margin % 2 ? total_margin / 2 + 1 : total_margin / 2;
  rectangle->start_x = left_margin + bar * bar_width;
  if (bar_width == 1)
    rectangle->end_x = rectangle->start_x;
  else
    rectangle->end_x = rectangle->start_x + bar_width - 2;
}

void BarGrapher::CalculateStartAndEndY(int height, double data,
                                       Rectangle *rectangle) {
  rectangle->end_y = height - 2;
  double height_portion;
  if (max_ <= min_)
    height_portion = 0.0;
  else
    height_portion = (data - min_) / (max_ - min_);
  height_portion = 0.9 * height_portion + 0.1;
  rectangle->start_y = (height - 1) - (height - 2) * height_portion;
}

}  // namespace video
}  // namespace pg
