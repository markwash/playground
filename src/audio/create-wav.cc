// Copyright 2011 <Mark Washenberger>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#include <sndfile.h>

#include <vector>

class SoundMaker {
 public:
  void AddPitch(float pitch) {
    pitches_.push_back(pitch);
    ResetWeights();
  }

  void ResetWeights() {
    float total = 0.0;
    for (int i = 0; i < pitches_.size(); i++)
      total += pitches_[i] * pitches_[i];
    weights_.clear();
    for (int i = 0; i < pitches_.size(); i++)
      weights_.push_back(pitches_[i] * pitches_[i] / total);
  }

  int16_t Sample(float time) {
    double phase;
    float component;
    float sample = 0;
    for (int i = 0; i < pitches_.size(); i++) {
      phase = 2 * M_PI * pitches_[i] * time;
      component = weights_[i] * static_cast<float>(sin(phase));
      sample += component;
    }
    return static_cast<int16_t>(32767 * sample);
  }

  void CreateFile(const char *path) {
    SF_INFO info;
    info.samplerate = 44100;
    info.channels = 1;
    info.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    SNDFILE *file = sf_open(path, SFM_WRITE, &info);
    int16_t point;
    float time;
    for (int i = 0; i < 2*44100; i++) {
      time = 1.0 * i / 44100;
      point = Sample(time);
      sf_write_short(file, &point, 1);
    }
    sf_close(file);
  }

 private:
  std::vector<float> pitches_;
  std::vector<float> weights_;
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s pitch1 [pitch2 [...]] file\n", argv[0]);
        return -1;
    }
  SoundMaker soundmaker;
  for (int i = 1; i < argc - 1; i++) {
    printf("adding pitch %f\n", atof(argv[i]));
    soundmaker.AddPitch(atof(argv[i]));
  }
    soundmaker.CreateFile(argv[argc - 1]);
    return 0;
}
