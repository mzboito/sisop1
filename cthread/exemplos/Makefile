all:
	gcc -c ../src/cthread.c -o ../bin/cthread.o -Wall
	ar crs ../lib/libcthread.a ../bin/cthread.o ../bin/support.o
	gcc -o barbeiro_tester barbeiro.c -L../lib -lcthread -Wall
	gcc -o exemplo_tester exemplo.c -L../lib -lcthread -Wall
	gcc -o filosofos_tester filosofos.c -L../lib -lcthread -Wall
	gcc -o mandel_tester mandel.c -L../lib -lcthread -Wall
	gcc -o prodcons_tester prodcons.c -L../lib -lcthread -Wall
	gcc -o series_tester series.c -L../lib -lcthread -Wall
	gcc -o teste_vetor_tester teste_vetor.c -L../lib -lcthread -Wall
	gcc -o tstSupp_tester tstSupp.c -L../lib -lcthread -Wall

clean:
	rm *_tester

