# Source file covered by the GNU Public License v3 
# See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/>

BUILT_SOURCES=parser.h
AM_YFLAGS=-d

bin_PROGRAMS=xsw xswconv #xsw2html
bin_SCRIPTS=xsw2pdf

xsw_SOURCES=xsw.c options.c file.c presentation.c slide.c cmd_text.c cmd_img.c list.c presenter.c execute.c color.c \
	          options.h file.h presentation.h slide.h cmd_text.h cmd_img.h list.h presenter.h execute.h color.h \
		  parser.y lexer.l
xsw_LDADD=$(SDL_LIBS) -L/usr/local/lib
xsw_CFLAGS=$(SDL_CFLAGS) -I/usr/local/include/SDL -Wall -Wextra -DUSE_SDL -DDATADIR=\""$(datadir)/xsw/"\" -DVERSION=\"$(VERSION)\"

xswconv_SOURCES=xswconv.c file.c presentation.c slide.c cmd_text.c cmd_img.c list.c presenter.c execute.c color.c \
	                  file.h presentation.h slide.h cmd_text.h cmd_img.h list.h presenter.h execute.h color.h \
		          parser.y lexer.l
xswconv_LDADD=$(SDL_LIBS) -L/usr/local/lib
xswconv_CFLAGS=$(SDL_CFLAGS) -I/usr/local/include/SDL -Wall -Wextra -DUSE_SDL -DDATADIR=\""$(datadir)/xsw/"\" -DVERSION=\"$(VERSION)\"

#xsw2html_SOURCES=x2h.c x2h_options.c x2h_template.c file.c presentation.c slide.c cmd_text.c cmd_img.c list.c presenter.c execute.c color.c util.c \
#		       x2h_options.h x2h_template.h file.h presentation.h slide.h cmd_text.h cmd_img.h list.h presenter.h execute.h color.h util.h \
#		       parser.y lexer.l
#xsw2html_LDADD=$(SDL_LIBS) -L/usr/local/lib
#xsw2html_CFLAGS=$(SDL_CFLAGS) -I/usr/local/include/SDL -Wall -Wextra -DUSE_SDL -DDATADIR=\""$(datadir)/xsw/"\" -DVERSION=\"$(VERSION)\"
