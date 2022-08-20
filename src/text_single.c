#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include "nth_prime.h"

void callback(int num, void *data)
{
  static int buffer = 0;
  char *str = (char *)data;
  buffer += sprintf(str + buffer, "%d\n", num);
}

int main(int argc, char **argv)
{
  FILE *txtFile;
  int prime, num = 1000000;
  char fileName[300], *str = (char *)calloc(10000000, sizeof(*str));

  sprintf(fileName, "%s/single.txt", argc ? dirname(argv[0]) : ".");

  txtFile = fopen(fileName, "w");

  if (txtFile == NULL)
  {
    fprintf(stderr, "Could not open the file.\n");
    exit(-1);
  }

  prime = nthPrime(num, (void *)str, callback);
  fputs(str, txtFile);

  free(str);
  fclose(txtFile);

  printf("%d\n", prime);

  return 0;
}