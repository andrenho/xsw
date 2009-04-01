BUILT_SOURCES=parser.h
AM_YFLAGS=-d

bin_PROGRAMS=xsw
xsw_SOURCES=xsw.c options.c file.c presentation.c xpresenter.c xslide.c images.c \
	          options.h file.h presentation.h xpresenter.h xslide.h images.h \
		  parser.y lexer.l
xsw_LDADD=$(X11) $(CAIRO_LIBS) $(MAGICK_LIBS) $(MAGICK_LDFLAGS)
xsw_CFLAGS=$(CAIRO_CFLAGS) $(MAGICK_CFLAGS) -DDEBUG
