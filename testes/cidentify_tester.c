#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"



int main(int argc, char *argv[]) {

char* stringu = (char*) malloc(30*sizeof(char));
  int bla = cidentify(stringu, 30);
  printf("%d\n",bla);
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
