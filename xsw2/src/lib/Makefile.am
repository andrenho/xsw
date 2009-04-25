lib_LTLIBRARIES=libxswstd.la

libxswstd_la_SOURCES = text.c text.h xswstd.h
libxswstd_la_LDFLAGS = -no-undefined -version-info 0:0:0

include_HEADERS = xswstd.h

install-exec-hook:
	ldconfig
