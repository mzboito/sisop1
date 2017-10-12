#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"



int main(int argc, char *argv[]) {

  csem_t *sem;
 // csem_init(sem,1);
  int retorno = cwait(sem);
  printf("%d\n",retorno);

  //csem_init(sem,2);
  //retorno = cwait(sem);
  //printf("%d\n",retorno);
 
}
