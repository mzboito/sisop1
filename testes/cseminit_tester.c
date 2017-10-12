#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"



int main(int argc, char *argv[]) {
  csem_t *sem = malloc(sizeof(csem_t));
  printf("before calling csem\n");
  int retorno = csem_init(sem,1);
  printf("%d\n",retorno);
  retorno = csem_init(sem,-5);
  printf("%d\n",retorno);
  retorno = csem_init(sem,0);
  printf("%d\n",retorno);
}
