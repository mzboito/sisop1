/*
Esse tester verifica a implementacao da cjoin.

*/

#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"

void foo1() {
  printf("Oi, eu sou a thread 1! :) \n");
  //for(int i=0;i < 100000; i++);
}

void foo2() {
  printf("Oi, eu sou a thread 2! :) \n");
  //for(int i=0;i < 100000; i++);
}

int main(int argc, char *argv[]) {

  int arg = 1;
  printf("I will now create two threads! \n");
  ccreate((void*)foo1, &arg,0);
  ccreate((void*)foo2, &arg,5);
  printf("This printf is after creating two new threads!\n");
  printf("Return cjoin for first thread: %d\n",cjoin(1));
  printf("Return cjoin again for the same thread (error): %d\n",cjoin(1));
  printf("Return cjoin for second thread: %d\n",cjoin(2));
  printf("And finally we are finished! Bye! \n");
}
