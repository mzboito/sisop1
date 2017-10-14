/*
  Esse tester verifica o sistema de prioridades da cthread.
  Criamos varias funcoes e vemos que apos todas serem interrompidas, elas sao
  reorganizadas de acordo com o seu tempo de execucao

*/

#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"

void foo1() {
for(int i=0;i < 100; i++);
printf("foo1 before cyield\n");
cyield();
printf("foo1 after cyield\n");
}

void foo2() {
for(int i=0;i < 1000; i++);
printf("foo2 before cyield\n");
cyield();
printf("foo2 after cyield\n");
}

void foo3() {
for(int i=0;i < 1000000; i++);
printf("foo3 before cyield\n");
cyield();
printf("foo3 after cyield\n");
}

void foo4() {
for(int i=0;i < 10000; i++);
printf("foo4 before cyield\n");
cyield();
printf("foo4 after cyield\n");
}

void foo5() {

for(int i=0;i < 100000; i++);
printf("foo5 before cyield\n");
cyield();
printf("foo5 after cyield\n");
}

int main(int argc, char *argv[]) {
  int arg = 1;
  printf("I will now create the threads\n");
  ccreate((void*)foo1, &arg,0);
  ccreate((void*)foo2, &arg,0);
  ccreate((void*)foo3, &arg,0);
  ccreate((void*)foo4, &arg,0);
  ccreate((void*)foo5, &arg,0);
  cjoin(5);
  cjoin(4);
  cjoin(3);
  cjoin(2);
  cjoin(1);

  printf("And finally we are finished\n");
}
