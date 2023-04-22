#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include "nth_prime.h"

/**
  This function receives a number and a string buffer as input arguments, and appends the
  number to the buffer as a new line. The "buffer" static variable stores the current number
  of elements in the string buffer.
  @param num The number to be appended to the buffer.
  @param data A pointer to the buffer where the numbers will be stored.
*/

void callback(int num, void *data)
{
  static int buffer = 0;
  char *str = (char *)data;
  buffer += sprintf(str + buffer, "%d\n", num);
}

/**
  This function writes all the n first prime numbers found by the nthPrime function and
  stored in a string buffer into a text file. The file name is "single.txt" and is saved
  in the same directory where the program is run.
  @param argc The number of command line arguments passed to the program.
  @param argv An array of strings containing the command line arguments.
  @return The exit status of the program.
*/

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