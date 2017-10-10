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
  ccreate(foo1, &arg,2);
  ccreate(foo2, &arg,4);
  ccreate(foo3, &arg,5);
  ccreate(foo4, &arg,1);
  ccreate(foo5, &arg,3);
  cyield();
  printf("I am on the main right now\n");
  printf("And finally we are finished\n");
}
