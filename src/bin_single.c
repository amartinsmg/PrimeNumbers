#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include "nth_prime.h"

/**
  This function receives a number and stores it in an array pointed by the void pointer
  "data". The "size" static variable stores the current number of elements in the array.
  @param num The number.
  @param data A void pointer to an array of integers.
*/

void callback(int num, void *data)
{
  static int size = 0;
  int *nums = (int *)data;
  nums[size++] = num;
}

/**
  This function stores the n first prime numbers found by the nthPrime function in an array
  and saves the array into a binary file. The file name is "single.bin" and is saved in
  the same directory where the program is run.
  @param argc The number of command line arguments passed to the program.
  @param argv An array of strings containing the command line arguments.
  @return The exit status of the program.
*/

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