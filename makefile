all: ./tuneTest

./tuneTest: list.c library.c main.c
	gcc -o list.c library.c main.c
run:
	./a.out
clean:
	rm -f a.out list.o library.o main.o *~
