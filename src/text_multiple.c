#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include "nth_prime.h"


void callback(int num, void *data)
{
  FILE *file = (FILE *)data;
  fprintf(file, "%d\n", num);
}

int main(int argc, char **argv)
{
  FILE *txtFile;
  int prime, num = 1000000;
  char fileName[300];

  sprintf(fileName, "%s/multiple.txt", argc ? dirname(argv[0]) : ".");

  remove(fileName);
  txtFile = fopen(fileName, "a");

  if(txtFile == NULL)
  {
    fprintf(stderr, "Could not open the file.\n");
    exit(-1);
  }

  prime = nthPrime(num, (void *)txtFile, callback);

  fclose(txtFile);

  printf("%d\n", prime);

  return 0;
}