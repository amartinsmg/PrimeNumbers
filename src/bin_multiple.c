#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include "nth_prime.h"

void callback(int num, void *data)
{
  FILE *file = (FILE *)data;
  fwrite(&num, sizeof(num), 1, file);
}

int main(int argc, char **argv)
{
  FILE *binFile;
  int prime, num = 1000000;
  char fileName[300];

  sprintf(fileName, "%s/multiple.bin", argc ? dirname(argv[0]) : ".");

  remove(fileName);
  binFile = fopen(fileName, "ab");

  if (binFile == NULL)
  {
    fprintf(stderr, "Could not open the file.\n");
    exit(-1);
  }

  prime = nthPrime(num, (void *)binFile, callback);

  fclose(binFile);

  printf("%d\n", prime);

  return 0;
}