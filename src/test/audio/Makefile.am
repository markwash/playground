AM_CXXFLAGS = -I$(top_srcdir)/src

check_PROGRAMS = \
	file-input-stream-test \
	sound-buffer-test

file_input_stream_test_SOURCES = \
	file-input-stream-test.cc

file_input_stream_test_LDFLAGS = -lboost_unit_test_framework-mt

sound_buffer_test_SOURCES = \
	sound-buffer-test.cc

sound_buffer_test_LDFLAGS = -lboost_unit_test_framework-mt

TESTS = $(check_PROGRAMS)
