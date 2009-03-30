# Start
AC_INIT([xsw], [0.1])
AM_INIT_AUTOMAKE([-Wall -Werror])

# Check for progams
AC_PROG_CC
AM_PROG_CC_C_O
AM_PROG_LEX
AC_PROG_YACC
AC_PROG_MAKE_SET

# Check for X11
AC_PATH_X
AC_CHECK_LIB(X11, XFlush, [X11=-lX11], [
		echo "Unable to find Xlib libraries. You must have the Xlib development libraries installed in order to install xdock."
		exit -1
])
AC_SUBST([X11])

# Check for Cairo
PKG_CHECK_MODULES(CAIRO, ["cairo"])
AC_SUBST(CAIRO_CFLAGS)
AC_SUBST(CAIRO_LIBS)

# Output files
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
		 Makefile
		 src/Makefile
		 ])
AC_OUTPUT