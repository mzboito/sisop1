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
int i = 0;
while (i < 20) {
printf("foo1 before cyield\n");
cyield();
printf("foo1 after cyield\n");
i++;
}
}

void foo2() {
int i = 0;
while (i < 70) {

printf("foo2 before cyield\n");
cyield();
printf("foo2 after cyield\n");
i++;
}
}

void foo3() {
int i = 0;
while (i < 16) {
printf("foo3 before cyield\n");
cyield();
printf("foo3 after cyield\n");
i++;
}
}

void foo4() {
int i = 0;
while (i < 30) {
printf("foo4 before cyield\n");
cyield();
printf("foo4 after cyield\n");
i++;
}
}

void foo5() {

int i = 0;
while (i < 80) {
printf("foo5 before cyield\n");
cyield();
printf("foo5 after cyield\n");
i++;
}
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
  return 0;
}
