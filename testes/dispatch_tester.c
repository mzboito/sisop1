#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"
#include "string.h"


void funcaoThreadExecuta() {

printf("Thread executa\n");
for(int i=0;i < 100000; i++);

}

int main(int argc, char *argv[]) {

int arg = 1;
printf("First testing getting the number of clocks");
startTimer();
funcaoThreadExecuta();
int timer = stopTimer();
int total = timer / 2294;
printf("Timer: %d, Timer / Mz: %d\n", timer, total);

printf("\n\n");

printf("I will now create the thread\n");
int teste = ccreate (funcaoThreadExecuta, &arg,0);
printf("Now the thread is on the ready list\n");
int totalTime = dispatcher();
printf("Total time was %d\n", totalTime);
printf("It would be soooo nice to finish the thread and come back heeere");

}
