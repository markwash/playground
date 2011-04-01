#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.64])
AC_INIT([playground], [0.0], [mwashenb@gmail.com])
AC_CONFIG_SRCDIR([src/])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_RANLIB

# Checks for libraries.
AC_CHECK_LIB([SDL], [SDL_SetVideoMode])
AC_CHECK_LIB([fftw3], [fftw_plan_dft_r2c_1d])
AC_CHECK_LIB([m], [sqrt])
AC_CHECK_LIB([portaudiocpp], [portaudio::System::instance])
AC_CHECK_LIB([sndfile], [sf_open])

# Checks for header files.
AC_CHECK_HEADERS([stdint.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_TYPE_INT16_T
AC_TYPE_UINT32_T

# Checks for library functions.
AC_FUNC_REALLOC
AC_CHECK_FUNCS([floor memset pow sqrt strdup])

AC_CONFIG_FILES([Makefile
                 src/Makefile
		 src/audio/Makefile
		 src/av/Makefile
		 src/video/Makefile
		 src/bin/Makefile
		 src/test/Makefile
		 src/test/audio/Makefile
		 src/test/av/Makefile
		 src/test/video/Makefile
		])
AC_OUTPUT
