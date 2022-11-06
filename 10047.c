#include "10047.h"
 
/* K: the sum, S: the size of selcetions */

bool subset(int numbers[], int n, int K, int S)
{
  if (n < S)
    return false;
  if (S == 0) 
    return (K == 0);
  if (K < 0)
    return false;
  return (subset(numbers, n - 1, K, S) ||
	  subset(numbers, n - 1, K - numbers[n - 1], S - 1));
}
