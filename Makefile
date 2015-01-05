main : tree.o
	cc -o main tree.o 

tree.o : tree.c
	cc -c tree.c

#reverse_str.o : reverse_str.c
#	cc -c reverse_str.c

clean :
	rm main tree.o
