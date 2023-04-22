#include <stdlib.h>

/**
  Calculates the nth prime number and calls a callback function with the n first prime numbers.
  @param n The index of the desired prime number
  @param data A pointer to a generic data type to be passed to the callback function
  @param callback A function pointer to the callback function that receives each prime number found and the data pointer
  @return The nth prime number
*/

int nthPrime(int n, void *data, void (*callback)(int, void *))
{
  int *numList = (int *)malloc(sizeof(*numList) * n),
      i, len = 0,
      num = 2;
  numList[len++] = 2;
  callback(2, data);
  while (len < n)
  {
    for (i = 0; i < len; i++)
    {
      if (num % numList[i] == 0)
        break;
      else if (numList[i] * numList[i] > num)
      {
        numList[len++] = num;
        callback(num, data);
        break;
      }
    }
    num++;
  }
  return numList[n - 1];
}
