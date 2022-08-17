#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nth_prime.h"


void callback(int num, void *data)
{
  static int buffer = 0;
  char *str = (char *)data;
  buffer += sprintf(str + buffer, "%d\n", num);
}

int main()
{
  char *str = (char *)calloc(10000000, sizeof(*str));
  FILE *txtFile;
  int prime, num = 1000000;

  txtFile = fopen("single.txt", "w");

  prime = nthPrime(num, (void *)str, callback);
  fputs(str, txtFile);

  fclose(txtFile);

  printf("%d\n", prime);

  return 0;
}