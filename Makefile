CC = gcc

all:  one tests

one:  Obj/main.o Obj/ceasar.o Obj/vizhiner.o Obj/atbash.o Obj/base64.o
	$(CC) Obj/*.o -o bin/Ciphers 

Obj/main.o: src/main.c
	$(CC) -c src/main.c -o Obj/main.o

Obj/ceasar.o: src/ceasar.c
	$(CC) -c src/ceasar.c -o Obj/ceasar.o

Obj/vizhiner.o: src/vizhiner.c
	$(CC) -c src/vizhiner.c -o Obj/vizhiner.o

Obj/atbash.o: src/atbash.c
	$(CC) -c src/atbash.c -o Obj/atbash.o

Obj/base64.o: src/base64.c
	$(CC) -c src/base64.c -o Obj/base64.o

clean:
	rm -f Obj/*.o
	rm -f tests/Obj/*.o
	make all

install:
	cp bin/Ciphers /usr/local/bin

unistall:
	rm -f /usr/local/bin/Ciphers

tests: tests/Obj/ceasar_test.o Obj/ceasar.o tests/Obj/vizhiner_test.o Obj/vizhiner.o tests/Obj/atbash_test.o Obj/atbash.o tests/Obj/maintest.o
	$(CC) tests/Obj/*.o Obj/ceasar.o Obj/vizhiner.o Obj/atbash.o -o tests/bin/Test

tests/Obj/maintest.o: tests/src/maintest.c
	$(CC) -c tests/src/maintest.c -o tests/Obj/maintest.o

tests/Obj/ceasar_test.o: tests/src/ceasar_test.c
	$(CC) -c tests/src/ceasar_test.c -o tests/Obj/ceasar_test.o

tests/Obj/vizhiner_test.o: tests/src/vizhiner_test.c
	$(CC) -c tests/src/vizhiner_test.c -o tests/Obj/vizhiner_test.o

tests/Obj/atbash_test.o: tests/src/atbash_test.c
	$(CC) -c tests/src/atbash_test.c -o tests/Obj/atbash_test.o
