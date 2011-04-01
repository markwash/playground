AM_CXXFLAGS = -I$(top_srcdir)/src

check_PROGRAMS = \
	bar-grapher-test

bar_grapher_test_SOURCES = \
	bar-grapher-test.cc

bar_grapher_test_LDFLAGS = -lboost_unit_test_framework-mt

bar_grapher_test_LDADD = \
	$(top_builddir)/src/video/libvideo.a

TESTS = $(check_PROGRAMS)
