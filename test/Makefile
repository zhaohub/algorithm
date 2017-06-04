all : commontest testcoroutine testdynamicarray testlist testqueue

commontest : commontest.o testfun.o
	$(CC) $(CFLAGS) -o $@ $^

testcoroutine : testcoroutine.o 
	$(CC) $(CFLAGS) -o $@ $^

testdynamicarray : testdynamicarray.o ../util/dynamic_array.o
	$(CC) $(CFLAGS) -o $@ $^

testlist : testlist.o ../util/link_list.o
	$(CC) $(CFLAGS) -o $@ $^
	
testqueue : testqueue.o ../util/link_queue.o
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	-rm *.o testcoroutine testdynamicarray testlist testqueue commontest
