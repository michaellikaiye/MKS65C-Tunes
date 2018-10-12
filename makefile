all: ./tuneTest run

./listtest: list.c library.c main.c
	gcc  -o tuneTest list.c library.c main.c
run:
	./tuneTest
clean:
	rm -f tuneTest list.o library.o main.o *~
