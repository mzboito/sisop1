#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"
#include "string.h"


int main(int argc, char *argv[]) {
char* stringu = (char*) malloc(20*sizeof(char));
  int bla = cidentify(stringu, 20);
  printf("%s\n",stringu);
  free(stringu);  

  int length = 20;
  char* str1 = (char*)malloc(sizeof(char)*(length + 1));
  printf("%d\n",cidentify(str1,length));
  free(str1);
  length = length - 5;
  char* str2 = (char*)malloc(sizeof(char)*(length + 1));
  printf("%d\n",cidentify(str2,length));
  free(str2);
  length = 0;
  char* str3 = (char*)malloc(sizeof(char)*(length + 1));
  printf("%d\n",cidentify(str3,length));
  free(str3);
}
