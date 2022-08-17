#include <stdio.h>
#include "nth_prime.h"

void callback(int num, void *data)
{
  return (void)0;
}

int main()
{
  int prime, num = 1000000;

  prime = nthPrime(num, 0, callback);
  
  printf("%d\n", prime);

  return 0;
}