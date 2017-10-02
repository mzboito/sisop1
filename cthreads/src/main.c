#include "../include/cthread.h"
#include "../include/cdata.h"
#include <stdio.h>

void* func0(void *arg) {
printf("Eu sou a thread ID0 imprimindo %d\n", *((int *)arg));
return;
}

void* func1(void *arg) {
printf("Eu sou a thread ID1 imprimindo %d\n", *((int *)arg));
}

void timerTester(){
	unsigned int tempo;
	startTimer();
	for(int i =0; i < 10; i++){
		printf("a");
	}
	tempo = stopTimer();
	printf("tempo foi de %u\n", tempo);
}

int main(int argc, char *argv[]) {
int      id0, id1, i;
//id0 = ccreate(func0, (void *)&i, NULL);
//id1 = ccreate(func1, (void *)&i, NULL);


printf("Eu sou a main apos a criacao de ID0 e ID1\n");
//cjoin(id0);
//cjoin(id1);
timerTester();
printf("Eu sou a main voltando para terminar o programa\n");
}
