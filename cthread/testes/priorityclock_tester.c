#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"

void foo1() {
//printf("I'm priority 2!\n");
for(int i=0;i < 100; i++);
printf("foo1 before cyield\n");
cyield();
printf("foo1 after cyield\n");
}

void foo2() {
//printf("I'm foo2!\n");
for(int i=0;i < 1000; i++);
printf("foo2 before cyield\n");
cyield();
printf("foo2 after cyield\n");
}

void foo3() {
//printf("I'm priority 5!\n");
for(int i=0;i < 10000; i++);
printf("foo3 before cyield\n");
cyield();
printf("foo3 after cyield\n");
}

void foo4() {
//printf("I'm priority 1!\n");
for(int i=0;i < 10000; i++);
printf("foo4 before cyield\n");
cyield();
printf("foo4 after cyield\n");
}

void foo5() {
//printf("I'm priority 3!\n");
for(int i=0;i < 100000; i++);
printf("foo5 before cyield\n");
cyield();
printf("foo5 after cyield\n");
}

int main(int argc, char *argv[]) {
  int arg = 1;
  printf("I will now create the threads\n");
  ccreate(foo1, &arg,0);
  ccreate(foo2, &arg,0);
  ccreate(foo3, &arg,0);
  ccreate(foo4, &arg,0);
  ccreate(foo5, &arg,0);
  cjoin(5);
  cjoin(4);
  cjoin(3);
  cjoin(2);
  cjoin(1);
  //printf("I am on the main right now\n");
  printf("And finally we are finished\n");
}
