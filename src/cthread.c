#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ucontext.h"
#include "../include/support.h"
#include "cdata.h"


//control variables

//a FILA2 for blockd, ready and finished
FILA2 ready;
FILA2 blocked;
FILA2 finished;
enum state {CREATED, READY, EXEC, BLOCKED, ENDED};
TCB_t *running; //the running TCB_t pointer points to the thread running
TCB_t main_tcb; //saves everything from the main flow

int last_tid = -1;

//scheduler context (not sure yet how to implement, but uses ucontext_t)

//header for others functions in the scheduler
void initialize();
int dispatcher();
int dispatch(TCB_t *task);
void addInSortedFILA2(PFILA2 pfila, void *content);

// main functions from cthread.h DO NOT CHANGE THE HEADER

int cidentify (char *name, int size){
  int length = 18;
  char names[length];
    strcpy(names,"Lisiane\nMarcely");
    if(size < length){
      return -1;
    }else{
      strcpy(name, names);
      return 0;
    }
}

int ccreate(void* (*start)(void*), void *arg, int prio) {
 char *stack = malloc(sizeof(char)*SIGSTKSZ); //looks more correct

if(last_tid < 0){ // it means it is the first created thread from the main flow
  initialize();
  //printf("last_tid %d\n", last_tid);
  // here we need to set and save the main flow
  getcontext(&main_tcb.context);
  ucontext_t *context = &main_tcb.context;
  //context->uc_link = ??
  context->uc_stack.ss_sp = stack;
  context->uc_stack.ss_size = sizeof(char)*SIGSTKSZ;
  makecontext(context, (void(*)(void)) start, 1, arg);
}

//now we create the new TCB structure
last_tid++;
TCB_t *tcb = malloc(sizeof(TCB_t));
tcb->tid = last_tid; //the first thread will be the thread 0
tcb->state = READY;
tcb->prio = prio;

//printf("last_tid %d\n", last_tid);
//now we need to create a new tcb-> context
getcontext(&tcb->context);
ucontext_t *context = &tcb->context;
//context->uc_link = ???
context->uc_stack.ss_sp = stack;
context->uc_stack.ss_size = sizeof(char)* SIGSTKSZ;
makecontext(context, (void (*)(void)) start, 1, arg);

//printf("I entendered the ccthread, but the tid is crazy\n");
//now we need to add it on the ready queue
AppendFila2(&ready, (void *)tcb);

 return tcb->tid;
}

int cyield(void);
int cjoin(int tid);
int csem_init(csem_t *sem, int count);
int cwait(csem_t *sem);
int csignal(csem_t *sem);


//other functions
void initialize(){
  last_tid = 0; //main is the pid = 0

  //scheduler context

  // maybe a terminate structure??

  //initialize the queues (ready, blocked and finished)
  CreateFila2(&ready);
  CreateFila2(&blocked);
  CreateFila2(&finished);

  main_tcb.tid = 0;
  main_tcb.state = READY; //because now we are going to the thread
  //[!!!] we are not settting priority for the main tcb

  running = &main_tcb;
}

int dispatcher(){
  //printf("Now I'm on the dispatcher\n");
  //sort the list

  //InsertAfterIteratorFila2(PFILA2 pFila, void *content);

  FirstFila2(&ready);
  TCB_t *task = (TCB_t *) GetAtIteratorFila2(&ready); //get first one
  //see if it this first one is not null (empty list)
  if(task){
    //printf("Now it will execute\n");
    //and then remove it from ready list and then put it to run
    DeleteAtIteratorFila2(&ready);

    int pTime = dispatch(task); //dispatching returns how much time was spent running the task
    return pTime;

  }

  //do we need to exit(0) it?
}

int dispatch(TCB_t *task){
  task->state = EXEC;
  running = task;
  //start the timer
  //printf("Inside dispatch!\n");
  startTimer();
  setcontext(&task->context);
  //stop the timer
  int pTime = stopTimer();
  int cpuMz = 2294;
  int total = pTime % cpuMz;
  //printf("Inside dispatch the total is %d\n", total);
  task->prio = task->prio + total; //set the new priority after execution
  return total;
}
