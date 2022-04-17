

main: test.o vector.o split.c
	gcc -Wall test.o vector.o -o test

build: test vector.o split.c
	gcc -Wall -c vector.o test.c -o test.o

vector: vector.h vector.c
	gcc -Wall -c vector.c -o vector.o

split: split.c
	gcc -Wall -c split.c -o split.o

run:
	./test
