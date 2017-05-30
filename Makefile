main : main.o util/bi_tree.o
	cc -o main main.o util/bi_tree.o

main.o : main.c include/tree.h 
	cc -c main.c

util/*:
	make -C util;

clean :
	rm main main.o util/*.o 
