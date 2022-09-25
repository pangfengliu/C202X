#include <stdio.h>
#include <assert.h>

int main()
{
  int n;
  assert(scanf("%d", &n) == 1);

  int sum, firstTerm, numTerm, diff;
  for (int i = 0; i < n; i++) {
    int number;
    assert(scanf("%d", &number) == 1);
#ifdef DEBUG
    printf("%d\n", number);
#endif
    switch (i) {
    case 0:
      sum = number;
      numTerm = 1;
      firstTerm = number;
      break;
    }
  }
  printf("%d %d %d\n", sum, numTerm, firstTerm);
  return 0;
}
