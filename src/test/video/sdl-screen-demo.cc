// Copyright 2011 <Mark Washenberger>

#include <stdlib.h>

#include "video/SDLScreen.h"

using pg::video::SDLScreen;
using pg::video::Rectangle;
using pg::video::Color;

static void SleepUntilQuit() {
  SDL_Event event;
  int event_found;
  while (true) {
    event_found = SDL_WaitEvent(&event);
    if (event_found && event.type == SDL_QUIT)
      return;
  }
}

int main(int argc, char **argv) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLScreen screen(SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE));
  Rectangle rectangle = {200, 200, 400, 600};
  Color color = {255, 0, 0};
  screen.Draw(rectangle, color);
  screen.Commit();
  SleepUntilQuit();
  screen.Clear();
  Rectangle rectangle2 = {400, 200, 700, 400};
  Color color2 = {128, 128, 255};
  screen.Draw(rectangle2, color2);
  screen.Commit();
  SleepUntilQuit();
  return EXIT_SUCCESS;
}
