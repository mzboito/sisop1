/*
Tester para a funcao csem_init.
A funcao aloca espaco para o semaforo e o inicializa, imprimindo o retorno

*/


#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"



int main(int argc, char *argv[]) {
  csem_t *sem = malloc(sizeof(csem_t));
  int retorno = csem_init(sem,1);
  printf("Retorno csem_init: %d\n",retorno);
  /*printf("Agora vou tentar inicializar um semaforo sem alocar e vai dar segmentation fault.\n");
  csem_t *sem2;
  retorno = csem_init(sem2,0);
  printf("Retorno csem_init nao alocado: %d\n",retorno);*/
  return 0;
}
