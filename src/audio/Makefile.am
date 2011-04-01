AM_CXXFLAGS = -I$(top_srcdir)/src

noinst_LIBRARIES = \
	libaudio.a

libaudio_a_SOURCES = \
	FileInputStream.h \
	FileInputStream.cc \
	FileOutputStream.h \
	FileOutputStream.cc \
	FourierTransformer.h \
	FourierTransformer.cc \
	MicInputStream.h \
	MicInputStream.cc \
	Pipe.h \
	Pipe.cc \
	SoundBuffer.h \
	SoundBuffer.cc

bin_PROGRAMS = pipe

pipe_SOURCES = pipe.cc
pipe_LDFLAGS = -lsndfile -lportaudiocpp -lfftw3 -lm -lSDL
pipe_LDADD = $(top_builddir)/src/audio/libaudio.a

noinst_PROGRAMS = create-wav

create_wav_SOURCES = create-wav.cc

create_wav_LDFLAGS = -lsndfile
