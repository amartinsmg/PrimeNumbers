#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include "nth_prime.h"

/**
  This function writes the given number to a text file.
  @param num The number to be written to the file.
  @param data A pointer to a FILE struct representing the text file.
*/

void callback(int num, void *data)
{
  FILE *file = (FILE *)data;
  fprintf(file, "%d\n", num);
}

/**
  This function generates the nth prime number and stores the first n prime numbers in a
  text file. The file name is "multiple.txt" and is saved in the same directory where the
  program is run.
  @param argc The number of command line arguments passed to the program.
  @param argv An array of strings containing the command line arguments.
  @return The exit status of the program.
*/

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