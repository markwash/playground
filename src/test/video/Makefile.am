AM_CXXFLAGS = -I$(top_srcdir)/src

check_PROGRAMS = \
	bar-grapher-test

bar_grapher_test_SOURCES = \
	bar-grapher-test.cc

bar_grapher_test_LDFLAGS = -lboost_unit_test_framework-mt

bar_grapher_test_LDADD = \
	$(top_builddir)/src/video/libvideo.a

noinst_PROGRAMS = \
	bar-grapher-sdl-demo \
	sdl-screen-demo

bar_grapher_sdl_demo_SOURCES = \
	bar-grapher-sdl-demo.cc

bar_grapher_sdl_demo_LDFLAGS = -lSDL

bar_grapher_sdl_demo_LDADD = \
	$(top_builddir)/src/video/libvideo.a

sdl_screen_demo_SOURCES = \
	sdl-screen-demo.cc

sdl_screen_demo_LDFLAGS = -lSDL

sdl_screen_demo_LDADD = \
	$(top_builddir)/src/video/libvideo.a


TESTS = $(check_PROGRAMS)
