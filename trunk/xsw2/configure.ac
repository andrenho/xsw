#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([xsw], [0.4.0], [andre.nho@gmail.com])
AC_CONFIG_SRCDIR([src/lib/text.h])
AC_CONFIG_HEADERS([config.h])
AC_DEFINE(VERSION, ["AC_PACKAGE_VERSION"], ["Configuring version..."])

AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_LIBTOOL
AC_PROG_CC
AM_PROG_CC_C_O
AM_PROG_LEX
AC_PROG_YACC
AC_PROG_MAKE_SET
AC_PROG_INSTALL

# libtool
AC_CONFIG_MACRO_DIR([m4])

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile po/Makefile.in
		 src/xsw:src/xsw.in
                 src/Makefile
                 src/as/Makefile
                 src/cp/Makefile
                 src/lib/Makefile
                 src/pp/Makefile
                 src/vm/Makefile])
AC_OUTPUT
