#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"

void printer(csem_t *sem){
  printf("%d\n", sem->count);
  cwait(sem);
  printf("TCHU TCHU PRINTING PRINTING PRINTING TCHU TCHU\n\n");
}

void foo(csem_t *sem){
  printf("just doing my stuff here\n");
  printer(sem);
}


int main(int argc, char *argv[]) {
  csem_t *sem = malloc(sizeof(csem_t));
  csem_init(sem,1);
  printf("Let's create some threads, guys\n");
  ccreate(foo, sem, 0);
  ccreate(foo, sem, 0);
  ccreate(foo, sem, 0);
  cjoin(2);

}
