BUILT_SOURCES=parser.h
AM_YFLAGS=-d

bin_PROGRAMS=xsw
xsw_SOURCES=xsw.c options.c file.c presentation.c slide.c cmd_text.c list.c \
	          options.h file.h presentation.h slide.h cmd_text.h list.h \
		  parser.y lexer.l
xsw_LDADD=$(SDL_LIBS) -L/usr/local/lib #-lSDL_image -lSDL_ttf -lSDL_gfx # TODO
xsw_CFLAGS=$(SDL_CFLAGS) -I/usr/local/share/SDL -Wall -Wextra -DUSE_SDL -DDATADIR=\""$(datadir)/xsw/"\" #-DDEBUG
