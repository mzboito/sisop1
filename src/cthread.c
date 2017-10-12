#include "stdio.h"
#include "stdlib.h"
#include "ucontext.h"
#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/cthread.h"

//control variables
//a FILA2 for blocked, ready and finished
FILA2 ready;
FILA2 blocked;
FILA2 finished;
enum state {CREATED, READY, EXEC, BLOCKED, ENDED};
TCB_t *running; //the running TCB_t pointer points to the thread running
TCB_t main_tcb; //saves everything from the main flow

int last_tid = -1; //initial tid (before main)
int cpuMz = 2294; //CPU mz rounded to the closest int value

//scheduler context (necessary to know what to do when a thread finishes its job)
ucontext_t scheduler_context;
char scheduler_stack[SIGSTKSZ];
ucontext_t terminate_context;
char terminate_stack[SIGSTKSZ];


//header for others functions in the scheduler
void initialize();
void terminate();
int dispatcher();
int dispatch(TCB_t *task);
void unblock_thread(int tid);
int updatePriority();
int addInSortedFILA2(PFILA2 fila, TCB_t *content);

// main functions from cthread.h DO NOT CHANGE THE HEADER

int cidentify (char *name, int size){
  int length = 30;
  if(size < length){
      return -1;
 }
  char names[] = {'L','i','s','i','a','n','e',':','2','5','2','7','3','9','\n',
                  'M','a','r','c','e','l','y',':','2','2','8','4','5','4'};
  int i = 0;
  while(i < length){
    *name = names[i];
    name++;
    i++;
  }
  /*for (int i = 0; i < length; i++) {
	*name = names[i];
	name++;
  }*/
  return 0;
}

int ccreate(void* (*start)(void*), void *arg, int prio) {
  char *stack = malloc(sizeof(char)*SIGSTKSZ); //looks more correct

  if(last_tid < 0){ // it means it is the first created thread from the main flow
    initialize();
    // here we need to set and save the main flow
    getcontext(&main_tcb.context);
    ucontext_t *context = &main_tcb.context;
    context->uc_stack.ss_sp = stack;
    context->uc_stack.ss_size = sizeof(char)*SIGSTKSZ;
    context->uc_link = &terminate_context; //!!! not sure yet
    makecontext(context, (void(*)(void)) start, 1, arg);
    //startTimer(); // starts timer for main thread
  }
  //now we create the new TCB structure
  last_tid++;
  TCB_t *tcb = malloc(sizeof(TCB_t));
  tcb->tid = last_tid; //the first thread will be the thread 0
  tcb->state = READY;
  tcb->prio = prio;
  tcb->wait_tid = -1;
  //now we need to create a new tcb-> context
  getcontext(&tcb->context);
  ucontext_t *context = &tcb->context;
  context->uc_stack.ss_sp = stack;
  context->uc_stack.ss_size = sizeof(char)* SIGSTKSZ;
  context->uc_link = &terminate_context;
  makecontext(context, (void (*)(void)) start, 1, arg);
  addInSortedFILA2(&ready, tcb);
  //AppendFila2(&ready, (void *)tcb); //now we need to add it on the ready queue
  return tcb->tid;
}

int cyield(void){
  if(last_tid < 0){ //there are no threads
      initialize();
  }
  if(running){ //if running pointer is not null
    //printf("shifting\n");
    running->state = READY;
    updatePriority(); //set the new priority after execution
    addInSortedFILA2(&ready, running);
    //AppendFila2(&ready,(void *)running);
    swapcontext(&running->context, &scheduler_context);
    return 0;
  }
  return -1;
}

int cjoin(int tid){
  TCB_t *tcb;
  //case there is already someone waiting
  FirstFila2(&blocked);
  do{
    tcb = (TCB_t *) GetAtIteratorFila2(&blocked);
    if(tcb){
      if(tcb->wait_tid == tid){
        return -1; //we only allow one thread to be waited for, ERROR
      }
    }
  }while(NextFila2(&blocked) == 0);

  //case the thread is dead
  FirstFila2(&finished);
  do{
    tcb = (TCB_t *) GetAtIteratorFila2(&finished);
    if(tcb){
      if(tcb->tid == tid){
        return -1; //if this tid is from a dead thread, ERROR
      }
    }
  }while(NextFila2(&finished) == 0); //while there are still elements left

  //else, it is okay
  running->state = BLOCKED;  //running state goes to blocked
  running->wait_tid = tid;
  //changes priority
  AppendFila2(&blocked, (void *) running); //adds this thread in the blocked list
  updatePriority(); //set the new priority
  swapcontext(&running->context, &scheduler_context);//switch with scheduler
  return 0;
}

int csem_init(csem_t *sem, int count) {
  if (count <= 0) {
	return -1;
  }
   sem = malloc (sizeof(csem_t));
   FILA2 filaSem;
   CreateFila2(&filaSem);
   sem->count = count;
   sem->fila = &filaSem;
   return 0;
}

int cwait(csem_t *sem) {
 if (!sem){ //if the structure null, something is wrong!
   return -1;
 }
 if (sem->count > 0){ //if there are resources left
   sem->count--; //subtract the resource for the running thread
   //no need for blocking anything, the thread will just enter the critical zone
 }
 else{ //if there are not resources left
   sem->count--; //subtract the resource
   running->state = BLOCKED; //bloqueia processo
   updatePriority(); //atualiza prioridade
   //AppendFila2(&blocked, (void *) running); //insere no fim da fila de bloqueados
   AppendFila2(sem->fila, (void *) running); //adds the thread in the list of waiting threads
   swapcontext(&running->context, &scheduler_context);
 }
   return 0; //finished
}

int csignal(csem_t *sem){
  if(!sem){ //testing for null structure
    return -1;
  }
  if(sem->count < 0){ //if there are threads waiting
    sem->count++;
    FirstFila2(sem->fila); //let's get a thread to unblock!
    TCB_t *tcb;
    do{
      tcb = (TCB_t*)GetAtIteratorFila2(sem->fila);
      if(tcb){ //if the tcb is not null
          tcb->state = READY;
          AppendFila2(&ready, (void*) tcb);
          //DeleteAtIteratorFila2(&blocked);
          DeleteAtIteratorFila2(sem->fila);
          return 0;
      }
    }while(NextFila2(sem->fila) == 0);
  } else{
    sem->count++; //if there are no threads waiting for the resource
    return 0;
  }
  return 0;
}

//other functions
void initialize(){
  last_tid = 0; //main is the pid = 0
  //scheduler context
  getcontext(&scheduler_context);
  scheduler_context.uc_stack.ss_sp = scheduler_stack;
  scheduler_context.uc_stack.ss_size = sizeof(scheduler_stack);
  scheduler_context.uc_link = NULL; //again, not sure
  makecontext(&scheduler_context, (void (*)(void))dispatcher, 0);
  getcontext(&terminate_context);
  terminate_context.uc_stack.ss_sp = terminate_stack;
  terminate_context.uc_stack.ss_size = sizeof(terminate_stack);
  terminate_context.uc_link = NULL;
  makecontext(&terminate_context, (void (*)(void))terminate, 0);
  //initialize the queues (ready, blocked and finished)
  CreateFila2(&ready);
  CreateFila2(&blocked);
  CreateFila2(&finished);
  running = malloc(sizeof(TCB_t)); //we need to separe memory area for running
  main_tcb.tid = 0;
  //!!!!!!!!!!! CHANGES HERE
  main_tcb.state = EXEC; //because now we are going to the thread
  main_tcb.wait_tid = -1;
  main_tcb.prio = 0;
  running = &main_tcb;
}

void terminate(){
  running->state = ENDED;
  updatePriority();
  //printf("finished without needing to save the clock\n");
  free(running->context.uc_stack.ss_sp); //you need to free the stack!!!
  AppendFila2(&finished, (void *)running); //goes to list of finished threads
  unblock_thread(running->tid);//if something was waiting, we should free it to continue execution
  setcontext(&scheduler_context); //goes back to the scheduler to set next thread
}

int dispatcher(){
  //printf("Now I'm on the dispatcher\n");
  //sort the list
  //InsertAfterIteratorFila2(PFILA2 pFila, void *content);
  FirstFila2(&ready);
  TCB_t *task = (TCB_t *) GetAtIteratorFila2(&ready); //get first one
  if(task){ //see if it this first one is not null (empty list)
    DeleteAtIteratorFila2(&ready); //and then remove it from ready list
    dispatch(task); //dispatching returns how much time was spent running the task
  }
  printf("There are no threads left!\n\n");
  exit(0);
}

int dispatch(TCB_t *task){
  task->state = EXEC;
  running = task;
  startTimer();
  setcontext(&task->context);
  return -1; // error return
}

void unblock_thread(int tid){
  FirstFila2(&blocked);
  TCB_t *blocked_tcb;
  do{
    blocked_tcb = (TCB_t*) GetAtIteratorFila2(&blocked);
    if(blocked_tcb){
      if(blocked_tcb->wait_tid == tid){ //if there is someone waiting
        blocked_tcb->wait_tid = -1;
        blocked_tcb->state = READY;
        addInSortedFILA2(&ready, blocked_tcb);
        //AppendFila2(&ready, (void *)blocked_tcb);
        DeleteAtIteratorFila2(&blocked);
      }
    }
  }while(NextFila2(&blocked) == 0); //while there are still elements left
  }

int updatePriority(){
  int pTime = stopTimer(); //gets the number of cpu cicles the process took
  if(pTime > 0){
    running->prio = running->prio + (pTime % cpuMz);
    //printf("Inside dispatch pid %d the total is %d\n", running->tid, running->prio);
    return 0;
  }
  return -1;
}

int addInSortedFILA2(PFILA2 fila, TCB_t *content){
  if(FirstFila2(fila) != 0){ //if the list is empty
    AppendFila2(fila, (void*) content);
    return 0;
  }
  //else
  TCB_t *tcb;
  do{
    tcb =  (TCB_t*)GetAtIteratorFila2(fila);
    if(tcb){
      //printf("I'm here searching for the thread\n");
      if (content->prio < tcb->prio){ //if the one we are inserting is smaller in priority value (higher in priority)
        InsertBeforeIteratorFila2(fila, (void*) content); //puts it in the position before TCB
        //printf("%d\n", content->prio);
        return 0;
      }
    }
  }while(NextFila2(fila) == 0); //while there are still elements left
  //if the code comes here, it means the content is the largest in priority value
  AppendFila2(fila, (void*) content); //puts it in the last position of the FILA2
  return 0;
}
