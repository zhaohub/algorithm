all: 
	(cd util; make)
	(cd test; make)
	(make main)

main : main.o util/bi_tree.o
	cc -o main main.o util/bi_tree.o

main.o : main.c include/tree.h 
	cc -c main.c

clean :
	(cd util;make clean)
	(cd test;make clean)
	rm main main.o
