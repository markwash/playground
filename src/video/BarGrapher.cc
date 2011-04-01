// Copyright 2011 <Mark Washenberger>

#include "video/BarGrapher.h"

using pg::video::Color;
using pg::video::Rectangle;
using pg::video::ScreenInterface;

namespace pg {
namespace video {

BarGrapher::BarGrapher(): max_(0.0) {}

void BarGrapher::Graph(ScreenInterface *screen,
                       const double *data, int data_size) {
  screen->Clear();
  UpdateMax(FindMax(data, data_size));
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

void BarGrapher::UpdateMax(double max) {
  if (max < 0.98 * max_)
    max_ *= 0.98;
  else
    max_ = max;
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
  if (data <= 0.0 || max_ == 0.0)
    portion = 0.0;
  else
    portion = data / max_;
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
  if (data < 0.0)
    data = 0.0;
  double height_portion;
  if (max_ == 0.0)
    height_portion = 0.2;
  else
    height_portion = 0.8 * data / max_ + 0.2;
  rectangle->start_y = (height - 1) - (height - 2) * height_portion;
}

}  // namespace video
}  // namespace pg
