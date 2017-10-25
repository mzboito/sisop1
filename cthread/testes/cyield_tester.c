/*
Teste de funcionamento da funcao cyield!
*/

#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"

void funcaoThreadExecuta() {
  printf("Thread executa :)\n");
//for(int i=0;i < 100000; i++);
}

int main(int argc, char *argv[]) {
	int arg = 1;
	printf("Criando duas threads simpaticas :)\n");
	ccreate((void*)funcaoThreadExecuta, &arg,0);
	ccreate((void*)funcaoThreadExecuta, &arg,5);
	printf("Elas agora estao na lista de aptos!\n");
	cyield();
	cyield();
	printf("Eventualmente nos voltamos aqui e terminamos com o programa ;)\n");
	return 0;
}
