
all : link_queue.o link_list.o bi_tree.o dynamic_array.o

link_queue.o : link_queue.c ../include/queue.h
	$(CC) $(CFLAGS) -c $<

link_list.o : link_list.c ../include/list.h
	$(CC) $(CFLAGS) -c $<

bi_tree.o : bi_tree.c ../include/tree.h
	$(CC) $(CFLAGS) -c $< 

dynamic_array.o : dynamic_array.c ../include/dynamic_array.h
	$(CC) $(CFLAGS) -c $<

clean:
	-rm *.o