all: list.o main.o library.o
	gcc list.o main.o library.o

library.o: library.c library.h list.h
	gcc -c library.c

list.o: list.c list.h
	gcc -c list.c

main.o: main.c list.h library.h
	gcc -c main.c
run:
	./a.out
clean:
	rm -f a.out list.o library.o main.o *~
