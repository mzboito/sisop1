all:
	gcc -c ../src/cthread.c -o ../bin/cthread.o -Wall
	ar crs ../lib/libcthread.a ../bin/cthread.o ../bin/support.o
	gcc -o addInSortedFILA2_tester addInSortedFILA2_tester.c -L../lib -lcthread -Wall
	gcc -o attributepassing_tester attributepassing_tester.c -L../lib -lcthread -Wall
	gcc -o ccreate_tester ccreate_tester.c -L../lib -lcthread -Wall
	gcc -o cidentify_tester cidentify_tester.c -L../lib -lcthread -Wall
	gcc -o cjoin_tester cjoin_tester.c -L../lib -lcthread -Wall
	gcc -o cseminit_tester cseminit_tester.c -L../lib -lcthread -Wall
	gcc -o csignal_tester csignal_tester.c -L../lib -lcthread -Wall
	gcc -o cwait_tester cwait_tester.c -L../lib -lcthread -Wall
	gcc -o cyield_tester cyield_tester.c -L../lib -lcthread -Wall
	gcc -o priorityclock_tester priorityclock_tester.c -L../lib -lcthread -Wall
	gcc -o priorityqueue_tester priorityqueue_tester.c -L../lib -lcthread -Wall

clean:
	rm *_tester

