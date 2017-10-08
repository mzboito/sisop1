#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

void funcaoThreadExecuta() {
printf("Thread executa\n");
for(int i=0;i < 100000; i++);
}

int main(int argc, char *argv[]) {
  int arg = 1;
  printf("I will now create the thread\n");
  ccreate(funcaoThreadExecuta, &arg,0);
  ccreate(funcaoThreadExecuta, &arg,5);
  ccreate(funcaoThreadExecuta, &arg,5);
  ccreate(funcaoThreadExecuta, &arg,5);
  printf("Now the thread is on the ready list\n");
  printf("It would be soooo nice to finish the thread and come back heeere\n");
  cyield();
  cjoin(2);
  cyield();
  cjoin(1);
  printf("And finally we are finished\n");
}
