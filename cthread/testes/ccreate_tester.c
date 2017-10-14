/*
Esse tester cria duas threads, e verifica se o tid esta sendo aumentado da forma
correta. Esse tester nao faz uso da cjoin, e por isso a funcao nao retorna ao main.

*/


#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"
#include "string.h"


void funcaoThreadExecuta() {

printf("Thread executa algo! :) \n");

}

int main(int argc, char *argv[]) {

int arg = 1;
printf("I will now create two threads...\n");
int teste = ccreate ((void*)funcaoThreadExecuta, &arg,0);
printf("The returned tid is: %d\n",teste);
teste = ccreate((void*)funcaoThreadExecuta, &arg, 0);
printf("The returned tid is: %d\n", teste);
}
