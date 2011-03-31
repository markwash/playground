AM_CXXFLAGS = -I$(top_srcdir)/src

check_PROGRAMS = \
	transform-visualizer-test \
	visual-sound-output-stream-test

transform_visualizer_test_SOURCES = \
	transform-visualizer-test.cc

transform_visualizer_test_LDFLAGS = \
	-lboost_unit_test_framework-mt

transform_visualizer_test_LDADD = \
	$(top_builddir)/src/audio/libaudio.a \
	$(top_builddir)/src/av/libav.a 


visual_sound_output_stream_test_SOURCES = \
	visual-sound-output-stream-test.cc

visual_sound_output_stream_test_LDFLAGS = \
	-lboost_unit_test_framework-mt

visual_sound_output_stream_test_LDADD = \
	$(top_builddir)/src/audio/libaudio.a \
	$(top_builddir)/src/av/libav.a 

TESTS = $(check_PROGRAMS)
