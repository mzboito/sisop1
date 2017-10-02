#include "../include/cthread.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  char *str1, *str2, *str3;
  int length = 20;
  str1 = (char *)malloc(sizeof(char)*(length + 1));
  printf("%d\n",cidentify(str3,length));
  length = length - 5;
  str2 = (char *)malloc(sizeof(char)*(length + 1));
  printf("%d\n",cidentify(str3,length));
  length = 0
  str3 = (char *)malloc(sizeof(char)*(length + 1));
  printf("%d\n",cidentify(str3,length));
}
