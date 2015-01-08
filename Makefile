main : main.o 
	cc -o main main.o

main.o : main.c tree.h 
queue.o : include/queue.c include/queue.h
	cc -c include/queue.c
tt.o : tt.c
	cc -c tt.c

clean :
	rm main tt.o queue.o
