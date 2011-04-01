AM_CXXFLAGS = -I$(top_srcdir)/src

bin_PROGRAMS = pipe

pipe_SOURCES = pipe.cc
pipe_LDFLAGS = -lsndfile -lportaudiocpp -lfftw3 -lm -lSDL
pipe_LDADD = \
	$(top_builddir)/src/audio/libaudio.a \
	$(top_builddir)/src/video/libvideo.a \
	$(top_builddir)/src/av/libav.a
