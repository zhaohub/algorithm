main : main.o util/bi_tree.o
	cc -o main main.o util/bi_tree.o

main.o : main.c include/tree.h 
	cc -c main.c

util/*:
	make -C util;

test/*:
	make -C test;

clean :
	rm main main.o util/*.o 
