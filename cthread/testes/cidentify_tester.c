/*
Esse tester confirma a implementacao da cidentify, imprimindo os valores de retorno.
*/


#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>
#include "stdlib.h"



int main(int argc, char *argv[]) {

  int length = 37;
  char* str1 = (char*)malloc(sizeof(char)*(length + 1));
  printf("Valid return for cidentify: %d\n",cidentify(str1,length));
  free(str1);
  length = length - 5;
  char* str2 = (char*)malloc(sizeof(char)*(length + 1));
  printf("Valid return for cidentify: %d\n",cidentify(str2,length));
  free(str2);
  length = 0;
  char* str3 = (char*)malloc(sizeof(char)*(length + 1));
  printf("Invalid return for cidentify: %d\n",cidentify(str3,length));
  free(str3);
  return 0;
}
