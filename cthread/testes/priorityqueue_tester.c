/*
Esse tester verifica a insercao na lista ordenada de threads aptas.
*/


#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"

void foo1() {
printf("I'm priority 2!\n");
for(int i=0;i < 1000000; i++);
}

void foo2() {
printf("I'm priority 4!\n");
for(int i=0;i < 1000000; i++);
}

void foo3() {
printf("I'm priority 5!\n");
for(int i=0;i < 1000000; i++);
}

void foo4() {
printf("I'm priority 1!\n");
for(int i=0;i < 1000000; i++);
}

void foo5() {
printf("I'm priority 3!\n");
for(int i=0;i < 1000000; i++);
}

int main(int argc, char *argv[]) {
  int arg = 1;
  printf("I will now create the threads\n");
  ccreate((void*)foo1, &arg,2);
  ccreate((void*)foo2, &arg,4);
  ccreate((void*)foo3, &arg,5);
  ccreate((void*)foo4, &arg,0);
  ccreate((void*)foo5, &arg,3);
  cjoin(3);
  printf("I am on the main right now\n");
  printf("And finally we are finished\n");
}
