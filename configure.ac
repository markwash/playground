#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.64])
AC_INIT([playground], [0.0], [mwashenb@gmail.com])
AC_CONFIG_SRCDIR([src/])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile
		 src/audio/Makefile
		 src/av/Makefile
		 src/video/Makefile
		 src/test/Makefile
		 src/test/audio/Makefile
		 src/test/av/Makefile
		])
AC_OUTPUT
