all : testcoroutine testdynamicarray testlist testqueue

testcoroutine : testcoroutine.o 
	cc -o $@ $^

testdynamicarray : testdynamicarray.o ../util/dynamic_array.o
	cc -o $@ $^

testlist : testlist.o ../util/link_list.o

	cc -o $@ $^
testqueue : testqueue.o ../util/link_queue.o
	cc -o $@ $^

clean : 
	-rm *.o testcoroutine testdynamicarray testlist testqueue
