#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"


int main(int argc, char *argv[]) {
  printf("I will now create the threads\n");
  TCB_t *tcb1 = malloc(sizeof(TCB_t));
  TCB_t *tcb2 = malloc(sizeof(TCB_t));
  TCB_t *tcb3 = malloc(sizeof(TCB_t));
  TCB_t *tcb4 = malloc(sizeof(TCB_t));
  FILA2 r;
  printf("Create list is a success if 0 == %d\n", CreateFila2(&r));
  tcb1->tid = 1;
  tcb1->prio = 1;
  tcb2->tid = 2;
  tcb2->prio = 5;
  tcb3->tid = 3;
  tcb3->prio = 3;
  tcb4->tid = 4;
  tcb4->prio = 0;
  addInSortedFILA2(&r,tcb1);
  addInSortedFILA2(&r,tcb2);
  addInSortedFILA2(&r,tcb4);
  addInSortedFILA2(&r,tcb3);
  FirstFila2(&r);
  do{
    tcb1 =  (TCB_t*) GetAtIteratorFila2(&r);
    printf("TID: %d PRIO %d\n", tcb1->tid, tcb1->prio);
  }while(NextFila2(&r) == 0);

  printf("And finally we are finished\n");
}
