// Copyright 2011 <Mark Washenberger>

#ifndef SRC_AUDIO_FOURIERTRANSFORMER_H_
#define SRC_AUDIO_FOURIERTRANSFORMER_H_

#include <fftw3.h>

#include "audio/SoundTransformerInterface.h"

namespace pg {
namespace audio {

class FourierTransformer: public pg::audio::SoundTransformerInterface {
 public:
  FourierTransformer(int input_size, int buckets);
  ~FourierTransformer();
  void Init();

  void Transform(int16_t *input);

  int input_size() const { return input_size_; }
  const double *output() const { return bucket_data_; }
  int output_size() const { return buckets_; }

 private:
  void LoadInput(int16_t *input);
  void AverageBuckets();
  double AverageOutputMagnitudesBetween(int left, int right);

  int input_size_;
  int buckets_;
  double *bucket_data_;
  double *real_input_;
  fftw_complex *complex_output_;
  int complex_output_size_;
  fftw_plan plan_;
};

}  // namespace audio
}  // namespace pg

#endif  // SRC_AUDIO_FOURIERTRANSFORMER_H_
