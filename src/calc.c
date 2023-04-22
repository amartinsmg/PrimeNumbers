#include <stdio.h>
#include "nth_prime.h"

/**
  This function is used as a placeholder for the nthPrime function's callback parameter
  when no callback is needed.
  @param num An integer representing the nth prime number.
  @param data A void pointer that can be used to pass additional data to the callback function.
  @return void
*/

void callback(int num, void *data)
{
  return (void)0;
}

/**
  This function calculates the nth prime number using the nthPrime function and a callback function.
  The calculated prime number is then printed to the console.
  @return The exit status of the program.
*/

int main()
{
  int prime, num = 1000000;

  prime = nthPrime(num, 0, callback);
  
  printf("%d\n", prime);

  return 0;
}