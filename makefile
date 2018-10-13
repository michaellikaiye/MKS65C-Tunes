all: ./tuneTest run

./tuneTest: list.c library.c main.c
	gcc  -o tuneTest list.c library.c main.c -g
run:
	valgrind ./tuneTest
clean:
	rm -f tuneTest list.o library.o main.o *~
