f := $(wildcard *.c)
cf := $(filter-out test.c,$(f))
of := $(cf:.c=.o)

.PYONY: all
all: $(of)
	
test: test.o
	gcc -Wall -o test.o test.c
	
.c.o:
	gcc -Wall -c -o $@ $<
	