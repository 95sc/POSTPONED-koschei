AC_PREREQ([2.69])
AC_INIT([koschei], [0.1.0], [95-st-capital@gmail.com])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h:config.h.in])
AM_INIT_AUTOMAKE([subdir-objects])
LT_PREREQ([2.4.6])
LT_INIT

# Checks for programs
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries

header_checks="stdio.h stdlib.h sys/socket.h sys/types.h netinet/in.h stdbool.h unistd.h"
for value in $header_checks; do
  AC_CHECK_HEADERS([${value}], [htest=yes], [htest=no])
  if test "x${htest}" = xno; then
    AC_MSG_FAILURE([Header: ${value} is required to build koschei.])
  fi
done

# Checks for typedefs, structures, and compiler characteristics

# Checks for library functions

# TODO: User options: server/client functionality
AC_CONFIG_FILES([Makefile
                 libkoslog/Makefile
                 src/Makefile])
AC_OUTPUT

