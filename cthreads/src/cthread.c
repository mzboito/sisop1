#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ucontext.h"
#include "cdata.h"

//control variables
//a FILA2 for blockd, ready abnd finished should be added here

enum state {CREATED, READY, EXEC, BLOCKED, ENDED};
TCB_t *running; //the running TCB_t pointer points to the thread running
TCB_t main_tcb; //saves everything from the main flow

int last_tid = -1;

//scheduler context (not sure yet how to implement, but uses ucontext_t)

//header for others functions in the scheduler
int dispatcher();
void initialize();

// main functions from cthread.h DO NOT CHANGE THE HEADER

int cidentify (char *name, int size){
  int length = 18;
  const char names[length];
    strcpy(names,"Lisiane\nMarcely");
    if(size < length){
      return -1;
    }else{
      strcpy(name, names);
      return 0;
    }
}

int ccreate(void* (*start)(void*), void *arg, int prio) {

 //char stack[SIGSTKSZ]; // pilha por enquanto
char *stack = malloc(sizeof(char)*SIGSTKSZ); //looks more correct

if(last_tid < 0){ // it means it is the first created thread from the main flow

  // here we need to create the queues, the scheduler context and the structures!!
  initialize();

  printf("last_tid %d\n", last_tid);
  // here we need to set and save the main flow
  getcontext(&main_tcb.context);
  ucontext_t *context = &main_tcb.context;
  //context->uc_link = ??
  context->uc_stack.ss_sp = stack;
  context->uc_stack.ss_size = sizeof(char)*SIGSTKSZ;
  makecontext(context, (void(*)(void)) start, 1, arg);
}

//now we create the new TCB structure
TCB_t *tcb = malloc(sizeof(TCB_t));
tcb->tid = last_tid++; //the first thread will be the thread 0
tcb->state = READY;

printf("last_tid %d\n", last_tid);
//now we need to create a new tcb-> context
getcontext(&tcb->context);
ucontext_t *context = &tcb->context;
//context->uc_link = ???
context->uc_stack.ss_sp = stack;
context->uc_stack.ss_size = sizeof(char)* SIGSTKSZ;
makecontext(context, (void (*)(void)) start, 1, arg);

printf("I entendered the ccthread, but the tid is crazy\n");
//now we need to add it on the ready queue


/* OLD VERSION
  TCB_t tcbThread = malloc (sizeof(TCB_t));
 ucontext_t ctx; // criar var contexto
 getcontext(&ctx);
 ctx.uc_stack.ss_sp = stack;
 ctx.uc_stack.ss_size = sizeof stack;
 if (identificadorThread == -1) {
     ctx.uc_link = &dispatcher;// pra onde vai depois da thread executar (a main aqui deu erro)
} else {
     ctx.uc_link = &dispatcher;
}
 identificadorThread++;
 tcbThread.tid = last_tid;
 tcbThread.state = 0;
 tcbThread.prio = 0;
 //tcbThread.context =
 makecontext(ctx.uc_link,start,0);*/

 return tcb->tid;
}

int cyield(void);
int cjoin(int tid);
//int csem_init(csem_t *sem, int count);
//int cwait(csem_t *sem);
//int csignal(csem_t *sem);


//other functions
void initialize(){
  last_tid = 0; //main is the pid = 0

  //scheduler context

  // maybe a terminate structure??

  //initialize the queues (ready, blocked and finished)

  main_tcb.tid = 0;
  main_tcb.state = READY; //because now we are going to the thread

  running = &main_tcb;
}
