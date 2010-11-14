# Relation Makefile
# Copyright (C) 2010 Tomás D'Stefano

uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')
OPTIMIZATION?=-O2
ifeq ($(uname_S),SunOS)
  CFLAGS?= -std=c99 -pedantic $(OPTIMIZATION) -Wall -W -D__EXTENSIONS__ -D_XPG6
  CCLINK?= -ldl -lnsl -lsocket -lm -lpthread
else
  CFLAGS?= -std=c99 -pedantic $(OPTIMIZATION) -Wall -W $(ARCH) $(PROF)
  CCLINK?= -lm -pthread
  TEST_C_LINK = -lcgreen
endif

CCOPT= $(CFLAGS) $(CCLINK) $(ARCH) $(PROF)
DEBUG?= -g -rdynamic -ggdb 

INSTALL_TOP= /usr/local
INSTALL_BIN= $(INSTALL_TOP)/bin
INSTALL= cp -p

# OBJ = 
# BENCHOBJ = 

BENCHMARK_PROGRAM = relation-benchmark

all: relation-benchmark	

# Deps (use make dep to generate this)
ae_epoll.o: ae_epoll.c
ae_kqueue.o: ae_kqueue.c
ae_select.o: ae_select.c

relation-benchmark: $(BENCHOBJ)
	$(CC) -o $(BENCHMARK_PROGRAM) $(CCOPT) $(DEBUG) $(BENCHOBJ)

clean:
	rm -rf $(BENCHMARK_PROGRAM) *.o *.gcda *.gcno *.gcov

dep:
	$(CC) -MM *.c

bench:
	benchmark/relation-benchmark

log:
	git log '--pretty=format:%ad %s (%cn)' --date=short

gprof:
	make PROF="-pg"

gcov:
	make PROF="-fprofile-arcs -ftest-coverage"

test:
	$(CC) -o 

install: all
	$(INSTALL) $(PRGNAME) $(INSTALL_BIN)
	$(INSTALL) $(BENCHMARK_PROGRAM) $(INSTALL_BIN)
