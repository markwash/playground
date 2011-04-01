// Copyright 2011 <Mark Washenberger>

#ifndef SRC_VIDEO_SDLSCREEN_H_
#define SRC_VIDEO_SDLSCREEN_H_

#include <SDL/SDL.h>

#include "video/ScreenInterface.h"

namespace pg {
namespace video {

class SDLScreen: public pg::video::ScreenInterface {
 public:
  explicit SDLScreen(SDL_Surface *surface);
  void Clear();
  void Commit();
  void Draw(Rectangle rectangle, Color color);

  int width() const { return surface_->w; }
  int height() const { return surface_->h; }

 private:
  void LockIfNecessary();
  void UnlockIfNecessary();

  bool locked_;
  SDL_Surface *surface_;
};

}  // namespace video
}  // namespace pg

#endif  // SRC_VIDEO_SDLSCREEN_H_
