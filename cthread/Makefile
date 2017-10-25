all:
	gcc -c src/cthread.c -o bin/cthread.o -Wall
	ar crs lib/libcthread.a bin/cthread.o bin/support.o
clean:
	rm bin/cthread.o 
	rm lib/libcthread.a
