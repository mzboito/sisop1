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
  printf("Let's create some threads, guys\n");
  ccreate(foo, &arg, 0);
  ccreate(foo, &arg, 0);
  ccreate(foo, &arg, 0);
  cjoin(3);

}
