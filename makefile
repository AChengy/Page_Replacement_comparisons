all: pagereplacement

pagereplacement: main.c main.h FIFO.c FIFO.h LRU.c LRU.h
	gcc -o pagereplacement main.c main.h FIFO.c FIFO.h LRU.c LRU.h -std=gnu99

.PHONY : clean
clean:
	rm -rf pagereplacement

