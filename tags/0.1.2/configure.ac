# Start
AC_INIT([xsw], [0.2.0])
AM_INIT_AUTOMAKE([-Wall -Werror])
AC_DEFINE(VERSION, ["AC_PACKAGE_VERSION"])

# Check for progams
AC_PROG_CC
AM_PROG_CC_C_O
AM_PROG_LEX
AC_PROG_YACC
AC_PROG_MAKE_SET

# Check for SDL
AC_CHECK_PROG(SDL_CFLAGS, sdl-config, `sdl-config --cflags`)
AC_CHECK_PROG(SDL_LIBS, sdl-config, `sdl-config --libs`)

# add other libraries
AC_CHECK_LIB(SDL_image, IMG_Load, [], [
	echo "Error: you need SDL_image in order to use xsw."
	exit -1
])
AC_CHECK_LIB(SDL_ttf, TTF_Init, [], [
	echo "Error: you need SDL_ttf in order to use xsw."
	exit -1
])
AC_CHECK_LIB(SDL_gfx, zoomSurface, [], [
	echo "Error: you need SDL_image in order to use xsw."
	exit -1
])

# Output files
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
		 Makefile
		 src/Makefile
		 data/Makefile
		 data/intro/xsw.xsw:data/intro/xsw.xsw.in
		 ])
AC_OUTPUT
