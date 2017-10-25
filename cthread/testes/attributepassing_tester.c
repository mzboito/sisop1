/*
Esse tester apenas testa passar argumentos para threads, para nos assegurarmos
que a makecontext esta guardando tudo de forma adequada.

*/

#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"

void foo(int *arg){
  printf("just doing my stuff here %d\n", *arg);
  //printer();
}

int main(int argc, char *argv[]) {
  int arg = 1;
  printf("Let's create some threads, guys!\n");
  ccreate((void*)foo, &arg, 0);
  int arg2 = 2;
  ccreate((void*)foo, &arg2, 0);
  int arg3 = 3;
  ccreate((void*)foo, &arg3, 0);
  cjoin(3);
  printf("Perfect! Goodbye! \n");
  return 0;
}
