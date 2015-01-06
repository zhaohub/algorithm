#main : tree.o
#	cc -o main tree.o 

#tree.o : tree.c
#	cc -c tree.c

#reverse_str.o : reverse_str.c
#	cc -c reverse_str.c

#clean :
#	rm main tree.o

main : queue.o tt.o
	cc -o main queue.o tt.o

queue.o : include/queue.c include/queue.h
	cc -c include/queue.c
tt.o : tt.c
	cc -c tt.c

clean :
	rm main tt.o queue.o
