// Copyright 2011 <Mark Washenberger>

#include "audio/MicInputStream.h"

#include <assert.h>

#include <portaudiocpp/AutoSystem.hxx>
#include <portaudiocpp/BlockingStream.hxx>
#include <portaudiocpp/Device.hxx>
#include <portaudiocpp/DirectionSpecificStreamParameters.hxx>
#include <portaudiocpp/StreamParameters.hxx>
#include <portaudiocpp/System.hxx>

namespace pg {
namespace audio {

MicInputStream::MicInputStream(): input_(NULL) {}

MicInputStream::~MicInputStream() {
  delete input_;
}

void MicInputStream::Init() {
  portaudio::System &system = portaudio::System::instance();
  const portaudio::Device &input_device = system.defaultInputDevice();
  portaudio::DirectionSpecificStreamParameters input_params;
  input_params.setDevice(input_device);
  input_params.setNumChannels(1);
  input_params.setSampleFormat(portaudio::INT16);
  input_params.setSuggestedLatency(input_device.defaultLowInputLatency());
  input_params.setHostApiSpecificStreamInfo(NULL);
  portaudio::StreamParameters params;
  params.setInputParameters(input_params);
  params.setOutputParameters(
      portaudio::DirectionSpecificStreamParameters::null());
  params.setSampleRate(44100);
  params.setFramesPerBuffer(paFramesPerBufferUnspecified);
  params.clearFlags();
  assert(params.isSupported());
  input_ = new portaudio::BlockingStream(params);
  input_->start();
}

bool MicInputStream::Read(pg::audio::SoundBuffer *buffer) {
  buffer->set_channels(1);
  int frames, frames_available = input_->availableReadSize();
  int min_frames = 2048;

  if (frames_available > buffer->max_frames())
    frames = buffer->max_frames();
  else if (frames_available < min_frames)
    frames = min_frames;
  else
    frames = frames_available;

  input_->read(buffer->data(), frames);
  buffer->set_frames(frames);

  return true;
}


}  // namespace audio
}  // namespace pg
