BUILT_SOURCES=parser.h
AM_YFLAGS=-d

bin_PROGRAMS=xsw
xsw_SOURCES=xsw.c options.c file.c presentation.c xpresenter.c xslide.c \
	          options.h file.h presentation.h xpresenter.h xslide.h \
		  parser.y lexer.l
xsw_LDADD=$(X11) $(CAIRO_LIBS)
xsw_CFLAGS=$(CAIRO_CFLAGS) -DDEBUG
