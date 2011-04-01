// Copyright 2011 <Mark Washenberger>

#include "audio/FourierTransformer.h"

#include <math.h>
#include <stdio.h>

namespace pg {
namespace audio {

FourierTransformer::FourierTransformer(int input_size, int buckets)
    : input_size_(input_size),
    buckets_(buckets),
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
  for (int i = 0; i < buckets_; i++) {
    bucket_left = i * complex_output_size_ / buckets_;
    bucket_right = (i + 1) * complex_output_size_ / buckets_;
    bucket_data_[i] =
        AverageOutputMagnitudesBetween(bucket_left, bucket_right);
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
