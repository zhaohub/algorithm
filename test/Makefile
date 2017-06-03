all : testcoroutine testdynamicarray testlist testqueue

testcoroutine : testcoroutine.o 
	cc -o testcoroutine testcoroutine.o

testdynamicarray : testdynamicarray.o ../util/dynamic_array.o
	cc -o testdynamicarray testdynamicarray.o ../util/dynamic_array.o

testlist : testlist.o ../util/link_list.o
	cc -o testlist testlist.o ../util/link_list.o

testqueue : testqueue.o ../util/link_queue.o
	cc -o testqueue testqueue.o ../util/link_queue.o

clean : 
	rm testcoroutine testdynamicarray testlist testqueue
