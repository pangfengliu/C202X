#include <stdio.h>
#include <assert.h>

int main()
{
  int n;
  assert(scanf("%d", &n) == 1);

  int sum, firstTerm, numTerm, diff, prev;
  int maxSum, maxFirstTerm, maxNumTerm;
  
  for (int i = 0; i < n; i++) {
    int number;
    assert(scanf("%d", &number) == 1);
#ifdef DEBUG
    printf("%d\n", number);
#endif
    if (i == 0) {
      maxSum = sum = number;
      maxNumTerm = numTerm = 1;
      maxFirstTerm = firstTerm = number;
    } else {
      if ((i == 1) || number - prev == diff) {
	sum += number;
	numTerm++;
	diff = number - prev;	/* for i == 1 */
      } else {			/* a new series */
	sum = number + prev;
	diff = number - prev;
	numTerm = 2;
	firstTerm = prev;
      }

      if (sum > maxSum || (sum == maxSum && numTerm > maxNumTerm) ||
	  (sum == maxSum && numTerm == maxNumTerm && firstTerm > maxFirstTerm)) {
	maxSum = sum;
	maxNumTerm = numTerm;
	maxFirstTerm = firstTerm;
      }
    }
#ifdef DEBUG
    printf("sum = %d firstTerm = %d\n", sum, firstTerm);
#endif
    prev = number;
  }
  printf("%d %d %d\n", maxSum, maxNumTerm, maxFirstTerm);
  return 0;
}
