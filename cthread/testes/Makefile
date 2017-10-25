all:
	gcc -c ../src/cthread.c -o ../bin/cthread.o
	gcc -c csignal_tester.c -o csignal_tester.o
	gcc -c addInSortedFILA2_tester.c -o addInSortedFILA2_tester.o
	gcc -c attributepassing_tester.c -o attributepassing_tester.o
	gcc -c ccreate_tester.c -o ccreate_tester.o
	gcc -c cidentify_tester.c -o cidentify_tester.o
	gcc -c cjoin_tester.c -o cjoin_tester.o
	gcc -c cyield_tester.c -o cyield_tester.o
	gcc -c cseminit_tester.c -o cseminit_tester.o
	gcc -c cwait_tester.c -o cwait_tester.o
	gcc -c priorityclock_tester.c -o priorityclock_tester.o
	gcc -c priorityqueue_tester.c -o priorityqueue_tester.o
	gcc -o csignal_tester -L../lib -libcthread csignal_tester.o
	gcc -o addInSortedFILA2_tester ../bin/support.o ../src/cthread.o addInSortedFILA2_tester.o
	gcc -o attributepassing_tester ../bin/support.o ../src/cthread.o attributepassing_tester.o
	gcc -o ccreate_tester ../bin/support.o ../src/cthread.o ccreate_tester.o
	gcc -o cidentify_tester ../bin/support.o ../src/cthread.o cidentify_tester.o
	gcc -o cyield_tester ../bin/support.o ../src/cthread.o cyield_tester.o
	gcc -o priorityclock_tester ../bin/support.o ../src/cthread.o priorityclock_tester.o
	gcc -o priorityqueue_tester ../bin/support.o ../src/cthread.o priorityqueue_tester.o
	gcc -o cjoin_tester ../bin/support.o ../src/cthread.o cjoin_tester.o
	gcc -o cseminit_tester ../bin/support.o ../src/cthread.o cseminit_tester.o
	gcc -o cwait_tester ../bin/support.o ../src/cthread.o cwait_tester.o

clean:
	rm ../bin/cthread.o addInSortedFILA2_tester.o attributepassing_tester.o csignal_tester.o ccreate_tester.o cidentify_tester.o cjoin_tester.o cseminit_tester.o cwait_tester.o cyield_tester.o priorityclock_tester.o priorityqueue_tester.o addInSortedFILA2_tester attributepassing_tester csignal_tester ccreate_tester cidentify_tester cjoin_tester cseminit_tester cwait_tester cyield_tester priorityclock_tester priorityqueue_tester

