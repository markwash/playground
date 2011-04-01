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

noinst_PROGRAMS = create-wav

create_wav_SOURCES = create-wav.cc

create_wav_LDFLAGS = -lsndfile
