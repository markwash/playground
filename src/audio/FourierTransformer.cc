// Copyright 2011 <Mark Washenberger>

#include "audio/FourierTransformer.h"

#include <math.h>
#include <stdio.h>

namespace pg {
namespace audio {

FourierTransformer::FourierTransformer(int input_size, int buckets,
                                       int relaxor)
    : input_size_(input_size),
    buckets_(buckets),
    relaxor_(relaxor),
    bucket_data_(NULL),
    real_input_(NULL),
    complex_output_(NULL),
    complex_output_size_(input_size / 2 + 1)
  {}

FourierTransformer::~FourierTransformer() {
  delete bucket_data_;
  fftw_free(real_input_);
  fftw_free(complex_output_);
  fftw_destroy_plan(plan_);
}

void FourierTransformer::Init() {
  bucket_data_ = new double[buckets_];
  for (int i = 0; i < buckets_; i++)
    bucket_data_[i] = 0.0;
  real_input_ = static_cast<double *>(
      fftw_malloc(sizeof(*real_input_) * input_size_));
  complex_output_ = static_cast<fftw_complex *>(
      fftw_malloc(sizeof(*complex_output_) * complex_output_size_));
  plan_ = fftw_plan_dft_r2c_1d(input_size_, real_input_,
                               complex_output_, FFTW_ESTIMATE);
}

void FourierTransformer::Transform(int16_t *input) {
  LoadInput(input);
  fftw_execute(plan_);
  AverageBuckets();
}

void FourierTransformer::LoadInput(int16_t *input) {
  for (int i = 0; i < input_size_; i++)
    real_input_[i] = input[i];
}

void FourierTransformer::AverageBuckets() {
  int bucket_left, bucket_right;
  double factor = pow(complex_output_size_, 1.0 / buckets_);
  double left = 1.0;
  double right = factor;
  double data;
  double relaxation = 1.0 / relaxor_;
  for (int i = 0; i < buckets_; i++) {
    bucket_left = floor(left);
    bucket_right = ceil(right);
    if (bucket_right > complex_output_size_)
      bucket_right = complex_output_size_;
    data = log(bucket_left * AverageOutputMagnitudesBetween(bucket_left,
                                                            bucket_right));
    bucket_data_[i] = (1.0 - relaxation) * bucket_data_[i] + relaxation * data;
    left = right;
    right *= factor;
  }
}

double FourierTransformer::AverageOutputMagnitudesBetween(int left,
                                                          int right) {
  if (left >= right)
    return 0.0;
  double real, imag, total_magnitude;
  for (int i = left; i < right; i++) {
    real = complex_output_[i][0];
    imag = complex_output_[i][1];
    total_magnitude += sqrt(real * real + imag * imag);
  }
  return total_magnitude / (right - left);
}

}  // namespace audio
}  // namespace pg
