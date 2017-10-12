#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"

void foo(int *arg){
  printf("just doing my stuff here %d, %d\n", &arg, arg);
  //printer();
}

/*void printer(){
  csem_t *sem;
  printf("csem init returns %d\n",csem_init(sem,1);
  int value = cwait(sem);
  if (value > 0){
      printf("TCHU TCHU PRINTING PRINTING PRINTING TCHU TCHU\n\n");
  }else{
    printf("nope\n");
  }

}
*/

int main(int argc, char *argv[]) {
  int arg = 1;
  printf("Let's create some threads, guys\n");
  ccreate(foo, &arg, 0);
  ccreate(foo, &arg, 0);
  ccreate(foo, &arg, 0);
  cjoin(3);

}
