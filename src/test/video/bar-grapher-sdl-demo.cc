// Copyright 2011 <Mark Washenberger>

#include <stdlib.h>

#include "video/BarGrapher.h"
#include "video/SDLScreen.h"

using pg::video::BarGrapher;
using pg::video::SDLScreen;

static double *ExtractDemoData(char **argv, int data_size) {
  double *data;
  data = new double[data_size];

  for (int i = 0; i < data_size; i++)
    data[i] = atof(argv[i]);

  return data;
}

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
  double *data;
  int data_size = argc - 1;

  SDL_Init(SDL_INIT_EVERYTHING);

  data = ExtractDemoData(argv + 1, data_size);

  SDLScreen screen(SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE));
  BarGrapher grapher;

  grapher.Graph(&screen, data, data_size);

  SleepUntilQuit();

  delete data;

  return EXIT_SUCCESS;
}
