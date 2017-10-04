#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ucontext.h"
#include "cdata.h"

int identificadorThread = -1;

int cidentify (char *name, int size){
  int length = 18;
  const char names[length];
    strcpy(names,"Lisiane e Marcely");
    if(size < length){
      return -1;
    }else{
      strcpy(name, names);
      return 0;
    }
}

void* funcaoThreadExecuta () {  // função que a thread vai executar

  printf("Thread executa");
}

void dispatcher () { // isso seria o escalonador (?)
}

int ccreate (void* funcaoAexecutar, void *arg, int prio) {

 char stack[SIGSTKSZ]; // pilha por enquanto

 //struct s_TCB tcbThread = malloc (sizeof(struct s_TCB)); // alocar tcb

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
 tcbThread.tid = identificadorThread;
 tcbThread.state = 0;
 tcbThread.prio = 0;
 tcbThread.context = makecontext(ctx.uc_link,funcaoThreadExecuta,0);

//inserir na fila

 return identificadorThread;
	
	
}

int ccreate (void* (*start)(void*), void *arg, int prio);
int cyield(void);
int cjoin(int tid);
//int csem_init(csem_t *sem, int count);
//int cwait(csem_t *sem);
//int csignal(csem_t *sem);
