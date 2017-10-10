#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"



int main(int argc, char *argv[]) {

csem_t *sem = (csem_t*) malloc (sizeof(csem_t));
int retorno = csem_init(sem,1);
printf("%d",retorno);

  //free(sem); 
}
