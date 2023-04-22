#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include "nth_prime.h"

/**
  This function writes the given number to a binary file.
  @param num The number to be written to the file.
  @param data A pointer to a FILE struct representing the binary file.
*/

void callback(int num, void *data)
{
  FILE *file = (FILE *)data;
  fwrite(&num, sizeof(num), 1, file);
}

/**
  This function generates the nth prime number and stores the first n prime numbers
  in a binary file. The file name is "multiple.bin" and is saved in the same directory
  where the program is run.
  @param argc The number of command line arguments passed to the program.
  @param argv An array of strings containing the command line arguments.
  @return The exit status of the program.
*/

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