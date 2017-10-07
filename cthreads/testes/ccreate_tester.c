#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"
#include "string.h"


void funcaoThreadExecuta() { 

printf("Thread executa");
  
}

int main(int argc, char *argv[]) {

int arg = 1;
printf("I will now create the thread\n");
int teste = ccreate (funcaoThreadExecuta, &arg,0);
printf("The returned tid is: %d\n",teste);

}
