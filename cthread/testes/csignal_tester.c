/*
Esse tester testa toda a nossa estrutura de semaforo: csem_init, cwait e cyield.
Nos emulamos o comportamento de uma impressora, conforme sugerido pelo professor.
Existem dois tipos de threads: threads que usam e não usam a impressora.
A impressora possui uma zona critica, e nos forçamos a thread a cair uma vez atraves
do uso de cyield. O nosso semaforo para este teste e exclusao mutua, mas isso e
facilmente modificavel na main.
*/


#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"

void printer(csem_t *sem){
  printf("Valor do semaforo antes da zona critica: %d\n", sem->count);
  cwait(sem);
  printf("\n\nTCHU TCHU PRINTING PRINTING PRINTING TCHU TCHU\n\n");
  printf("The thread is losing the printer in the middle!!\n\nBUM!\n\n");
  cyield();
  printf("Finishing with the printer, one sec...\n");
  csignal(sem);

}

void foo(csem_t *sem){
  printf("Thread: OMG I WANT TO PRINT SOMETHING!!\n");
  printer(sem);
}

void foo2(){
  printf("Thread: I'm just a regular thread, I don't like printers\n");
}


int main(int argc, char *argv[]) {
  csem_t *sem = malloc(sizeof(csem_t));
  csem_init(sem,1);
  printf("Creating some threads inside the main\n\n\n");
  ccreate((void*)foo, sem, 0);
  ccreate((void*)foo, sem, 0);
  ccreate((void*)foo2, sem, 0);
  ccreate((void*)foo, sem, 0);
  cjoin(4);
  printf("Ok, this was a mess, but everybody printed their stuff! Bye! :)\n");
}
