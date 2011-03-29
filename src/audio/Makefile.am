AM_CXXFLAGS = -I$(top_srcdir)/src

noinst_LIBRARIES = \
	libaudio.a

libaudio_a_SOURCES = \
	FileInputStream.h \
	FileInputStream.cc \
	SoundBuffer.h \
	SoundBuffer.cc

bin_PROGRAMS = record

record_SOURCES = record.cc

noinst_PROGRAMS = create-wav

create_wav_SOURCES = create-wav.cc

create_wav_LDFLAGS = -lsndfile
