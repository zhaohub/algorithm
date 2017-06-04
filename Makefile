CC ?= gcc
CFLAGS ?= -g -Wall -O2
SHARED := -fPIC --shared

export CC CFLAGS SHARED

SUBDIRS = util test

all : main $(SUBDIRS)
 
main : main.o util/bi_tree.o
	$(CC) $(CFLAGS) -o $@ $^

$(SUBDIRS) : ECHO
	+$(MAKE) -C $@

ECHO : 
	@echo begin compile

.PHONY :
clean :
	(cd util;make clean)
	(cd test;make clean)
	-rm main main.o
