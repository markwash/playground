// Copyright 2011 <Mark Washenberger>
#include <stdlib.h>
#include <string.h>
#include <portaudiocpp/AutoSystem.hxx>

#include <vector>

#include "audio/FileInputStream.h"
#include "audio/FileOutputStream.h"
#include "audio/MicInputStream.h"
#include "audio/Pipe.h"

using pg::audio::FileInputStream;
using pg::audio::FileOutputStream;
using pg::audio::MicInputStream;
using pg::audio::Pipe;
using pg::audio::SoundInputStreamInterface;
using pg::audio::SoundOutputStreamInterface;


class Token {
 public:
  explicit Token(const char *token)
      : token_(token), token_copy_(NULL), key_(NULL) {}
  ~Token() { delete token_copy_; }

  void Init() {
    token_copy_ = strdup(token_);
    char *strtok_context;
    key_ = strtok_r(token_copy_, ":", &strtok_context);
    char *arg;
    while (true) {
      arg = strtok_r(NULL, ",", &strtok_context);
      if (arg == NULL)
        break;
      args_.push_back(arg);
    }
  }

  const char *key() const { return key_; }
  const std::vector<char *> *args() const { return &args_; }

 private:
  const char *token_;
  char *token_copy_;
  char *key_;
  std::vector<char *> args_;
};

static SoundInputStreamInterface *CreateInputStreamOrDie(
    const Token *token) {

  if (strcmp(token->key(), "file") == 0) {
    FileInputStream *input = new FileInputStream(token->args()->at(0));
    input->Init();
    return input;
  } else if (strcmp(token->key(), "mic") == 0) {
    MicInputStream *input = new MicInputStream();
    input->Init();
    return input;
  }

  fprintf(stderr, "Unrecognized key: %s\n", token->key());
  exit(EXIT_FAILURE);
  return NULL;
}

static SoundOutputStreamInterface *CreateOutputStreamOrDie(
    const Token *token) {

  if (strcmp(token->key(), "file") == 0) {
    FileOutputStream *output = new FileOutputStream(token->args()->at(0));
    output->Init();
    return output;
  }

  fprintf(stderr, "Unrecognized key: %s\n", token->key());
  exit(EXIT_FAILURE);
  return NULL;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
    return EXIT_FAILURE;
  }

  portaudio::AutoSystem auto_sys;

  Token input_token(argv[1]);
  Token output_token(argv[2]);

  input_token.Init();
  output_token.Init();

  SoundInputStreamInterface *in;
  SoundOutputStreamInterface *out;

  in = CreateInputStreamOrDie(&input_token);
  out = CreateOutputStreamOrDie(&output_token);

  Pipe pipe(in, out);
  pipe.run_until_finished();

  delete in;
  delete out;

  return EXIT_SUCCESS;
}
