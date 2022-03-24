AC_PREREQ([2.69])
AC_INIT([koschei], [0.1.0], [95-st-capital@gmail.com])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h:config.h.in])
AM_INIT_AUTOMAKE

# Checks for programs
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries

# Checks for header files
AC_CHECK_HEADERS([stdlib.h], [], [have_stdio=no])
if test "x${have_stdio}" = xno; then
  AC_MSG_FAILURE([stdio.h is required to build koschei.])
fi

# Checks for typedefs, structures, and compiler characteristics

# Checks for library functions

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT

