# Relation Makefile
# Copyright (C) 2010 Tomás D'Stefano

OPTIMIZATION?=-O2
LOADPATH?= -I source -I source/lib
CFLAGS?= $(LOADPATH) -std=c99 -pedantic $(OPTIMIZATION) -Wall -W $(ARCH) $(PROF)
CCLINK?= -lm -pthread -lprofiler
CCOPT= $(CFLAGS) $(LOAD_PATH) $(CCLINK) $(ARCH) $(PROF)
DEBUG?= -g -rdynamic -ggdb 

INSTALL_TOP= /usr/local
INSTALL_BIN= $(INSTALL_TOP)/bin
INSTALL= cp -p

BENCHMARK_PROGRAM = benchmarks/relation-benchmark
BENCHOBJ = benchmarks/simple_query.o source/relation.o source/lib/append_to_string.o source/lib/integer_to_char.o source/relation/select_manager.o source/relation/sql_literal.o source/relation/table.o source/relation/tree_manager.o source/relation/nodes/select_statement.o source/relation/visitors/to_sql.o source/relation/visitors/visitor.o

all: relation-benchmark	

# Deps (use make dep to generate this)

relation-benchmark: $(BENCHOBJ)
	$(CC) -o $(BENCHMARK_PROGRAM) $(CCOPT) $(DEBUG) $(BENCHOBJ)

clean:
	rm -rf $(BENCHMARK_PROGRAM) *.o *.gcda *.gcno *.gcov

dep:
	$(CC) -MM *.c

bench:
	benchmarks/relation-benchmark

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
