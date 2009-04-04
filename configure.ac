# Start
AC_INIT([xsw], [0.1])
AM_INIT_AUTOMAKE([-Wall -Werror])

# Check for progams
AC_PROG_CC
AM_PROG_CC_C_O
AM_PROG_LEX
AC_PROG_YACC
AC_PROG_MAKE_SET

# Check for SDL
AC_CHECK_PROG(SDL_CFLAGS, sdl-config, `sdl-config --cflags`)
AC_CHECK_PROG(SDL_LIBS, sdl-config, `sdl-config --libs`)

# TODO - add other libraries

# Output files
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
		 Makefile
		 src/Makefile
		 data/Makefile
		 ])
AC_OUTPUT
