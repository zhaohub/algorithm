CC ?= gcc
CFLAGS ?= -Wall -O2


all: 
	(cd util; make)
	(cd test; make)
	(make main)

main : main.o util/bi_tree.o
	$(CC) $(CFLAGS) -o $@ $^

main.o : main.c include/tree.h 
	$(CC) $(CFLAGS) -c $<
	
.PHONY :
clean :
	(cd util;make clean)
	(cd test;make clean)
	-rm main main.o
