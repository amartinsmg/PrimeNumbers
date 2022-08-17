#include <stdlib.h>

int nthPrime(int n, void *data, void (*callback)(int, void*))
{
  int *numList = (int *)malloc(sizeof(int) * n);
  numList[0] = 2;
  int len = 1,
      num = 2;
  callback(2, data);
  while (len < n)
  {
    for (int i = 0; i < len; i++)
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
