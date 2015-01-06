OBJS=link_queue.o bi_tree.o

util.o:$(OBJS)
	ld -r -o $(OBJS)
	sync

link_queue.o: link_queue.c ../include/queue.h
	gcc -c link_queue.c ../include/queue.h

bi_tree.o:bi_tree.c ../include/tree.h
	gcc -c bi_tree.c ../include/tree.h



