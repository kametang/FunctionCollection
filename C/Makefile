cf := $(wildcard *.c)
of := $(cf:.c=.o)

.PYONY: all
all: $(of)
	
.c.o:
	gcc -Wall -c -o $@ $<
	
