SUBDIRS = modules/client modules/server

bin_PROGRAMS = koschei
koschei_SOURCES = main.c application.h
koschei_CPPFLAGS = -I$(top_srcdir)/include
koschei_LDADD = $(top_builddir)/libkoslog/libkoslog.la -dlopen modules/client/client.la -dlopen modules/server/server.la
