all:
	gcc -c ../src/cthread.c -o ../bin/cthread.o
	gcc -c barbeiro.c -o barbeiro.o
	gcc -c exemplo.c -o exemplo.o
	gcc -c filosofos.c -o filosofos.o
	gcc -c mandel.c -o mandel.o
	gcc -c prodcons.c -o prodcons.o
	gcc -c series.c -o series.o
	gcc -c teste_vetor.c -o teste_vetor.o
	gcc -c tstSupp.c -o tstSupp.o
	gcc -o barbeiro ../bin/support.o ../src/cthread.o barbeiro.o
	gcc -o exemplo ../bin/support.o ../src/cthread.o exemplo.o
	gcc -o filosofos ../bin/support.o ../src/cthread.o filosofos.o
	gcc -o mandel ../bin/support.o ../src/cthread.o mandel.o
	gcc -o prodcons ../bin/support.o ../src/cthread.o prodcons.o
	gcc -o series ../bin/support.o ../src/cthread.o series.o
	gcc -o teste_vetor ../bin/support.o ../src/cthread.o teste_vetor.o
	gcc -o tstSupp ../bin/support.o ../src/cthread.o tstSupp.o

clean:
	rm ../bin/cthread.o barbeiro.o exemplo.o filosofos.o mandel.o prodcons.o series.o teste_vetor.o tstSupp.o barbeiro exemplo filosofos mandel prodcons series teste_vetor tstSupp 

