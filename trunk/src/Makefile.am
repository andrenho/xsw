BUILT_SOURCES=parser.h
AM_YFLAGS=-d

bin_PROGRAMS=xsw
xsw_SOURCES=xsw.c options.c file.c presentation.c presenter.c \
	          options.h file.h presentation.h presenter.h \
		  parser.y lexer.l
xsw_LDADD=$(SDL_LIBS)
xsw_CFLAGS=$(SDL_CFLAGS) -DDEBUG
