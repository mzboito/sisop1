

int cidentify (char *name, int size){
  int length = 18;
  char names[length];
  names = "Lisiane e Marcely";
    if(size < length){
      return -1;
    }else{
      name = names;
      return 0;
    }
}


int ccreate (void* (*start)(void*), void *arg, int prio);
int cyield(void);
int cjoin(int tid);
//int csem_init(csem_t *sem, int count);
//int cwait(csem_t *sem);
//int csignal(csem_t *sem);
