// Copyright 2011 <Mark Washenberger>

#include "video/SDLScreen.h"

#include <stdint.h>

namespace pg {
namespace video {

SDLScreen::SDLScreen(SDL_Surface *surface)
    : locked_(false), surface_(surface) {}

void SDLScreen::Clear() {
  LockIfNecessary();
  memset(surface_->pixels, 0, surface_->h * surface_->pitch);
}

void SDLScreen::Commit() {
  UnlockIfNecessary();
  SDL_UpdateRect(surface_, 0, 0, 0, 0);
}

void SDLScreen::Draw(Rectangle rectangle, Color color) {
  uint32_t raw_color;
  uint32_t *pixel;

  raw_color = SDL_MapRGB(surface_->format, color.red, color.green, color.blue);

  LockIfNecessary();
  for (int i = rectangle.start_x; i <= rectangle.end_x; i++) {
    for (int j = rectangle.start_y; j <= rectangle.end_y; j++) {
      pixel = static_cast<uint32_t *>(surface_->pixels);
      pixel += j * surface_->pitch / 4 + i;
      *pixel = raw_color;
    }
  }
}

void SDLScreen::LockIfNecessary() {
  if (!locked_ && SDL_MUSTLOCK(surface_))
    SDL_LockSurface(surface_);
}

void SDLScreen::UnlockIfNecessary() {
  if (locked_ && SDL_MUSTLOCK(surface_))
    SDL_UnlockSurface(surface_);
}

}  // namespace video
}  // namespace pg
