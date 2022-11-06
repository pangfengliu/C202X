#include "subset.h"
 
/* K: the sum, S: the size of selcetions */
int subset(int numbers[], int n, int K, int S)
{
  if (n < S)
    return 0;
  if (S == 0) 
    return (K == 0);
  if (K < 0)
    return 0;
  return (subset(numbers, n - 1, K, S) ||
	  subset(numbers, n - 1, K - numbers[n - 1], S - 1));
}
