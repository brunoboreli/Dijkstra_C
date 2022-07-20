
all: exemplo

exemplo: exemplo.c lista.o pq_heap.o digrafolista.o
	gcc $^ -o $@

%.o: %.c %.h
	gcc -c $<

