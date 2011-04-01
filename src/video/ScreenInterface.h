// Copyright 2011 <Mark Washenberger>

#ifndef SRC_VIDEO_SCREENINTERFACE_H_
#define SRC_VIDEO_SCREENINTERFACE_H_

namespace pg {
namespace video {

class Color {
 public:
  int red;
  int green;
  int blue;
};

class Rectangle {
 public:
  int start_x;
  int start_y;
  int end_x;
  int end_y;
};

class ScreenInterface {
 public:
  virtual ~ScreenInterface() {}
  virtual void Clear() = 0;
  virtual void Commit() = 0;
  virtual void Draw(Rectangle rectangle, Color color) = 0;

  virtual int width() const = 0;
  virtual int height() const = 0;
};

}  // namespace video
}  // namespace pg

#endif  // SRC_VIDEO_SCREENINTERFACE_H_
