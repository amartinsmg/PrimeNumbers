#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include "nth_prime.h"

void callback(int num, void *data)
{
  static int size = 0;
  int *nums = (int *)data;
  nums[size++] = num;
}

int main(int argc, char **argv)
{
  FILE *binFile;
  int prime, num = 1000000,
             *nums = (int *)calloc(num, sizeof(*nums));
  char fileName[300];

  sprintf(fileName, "%s/single.bin", argc ? dirname(argv[0]) : ".");

  binFile = fopen(fileName, "wb");

  if (binFile == NULL)
  {
    fprintf(stderr, "Could not open the file.\n");
    exit(-1);
  }

  prime = nthPrime(num, (void *)nums, callback);

  fwrite(nums, sizeof(*nums), num, binFile);

  free(nums);
  fclose(binFile);

  printf("%d\n", prime);

  return 0;
}