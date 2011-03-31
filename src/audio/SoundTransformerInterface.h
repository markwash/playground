// Copyright 2011 <Mark Washenberger>

#ifndef SRC_AUDIO_SOUNDTRANSFORMERINTERFACE_H_
#define SRC_AUDIO_SOUNDTRANSFORMERINTERFACE_H_

#include <stdint.h>

namespace pg {
namespace audio {

class SoundTransformerInterface {
 public:
  virtual ~SoundTransformerInterface() {}

  virtual void Transform(int16_t *input) = 0;

  virtual int input_size() const = 0;
  virtual const double *output() const = 0;
  virtual int output_size() const = 0;
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_SOUNDTRANSFORMERINTERFACE_H_
