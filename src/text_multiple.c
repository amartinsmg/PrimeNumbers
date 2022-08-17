#include <stdio.h>
#include <stdlib.h>
#include "nth_prime.h"


void callback(int num, void *data)
{
  FILE *file = (FILE *)data;
  fprintf(file, "%d\n", num);
}

int main()
{
  FILE *txtFile;
  int prime, num = 1000000;

  remove("multiple.txt");
  txtFile = fopen("multiple.txt", "a");

  prime = nthPrime(num, (void *)txtFile, callback);

  fclose(txtFile);

  printf("%d\n", prime);

  return 0;
}