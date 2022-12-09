#include <stdio.h>

int min(int a, int b)
{
  return (a < b? a : b);
}
  
int main()
{
  int N, M, k;
  scanf("%d%d%d", &N, &M, &k);
  int R = min(M, N);
    
  int index = 1;
  for (int round = 1; round <= R; round++) {
    int width = M - round + 1;
#ifdef DEBUG
    printf("row %d from %d to %d\n", round, index, index + width - 1);
#endif
    if (k >= index && k < index + width) {
      printf("%d %d\n", round, k - index + round);
      return 0;
    }
    index += width;

    if (round < N) {
      int height = N - round;
#ifdef DEBUG
      printf("col %d from %d to %d\n", round, index, index + height - 1);
#endif
      if (k >= index && k < index + height) {
	printf("%d %d\n", k - index + round + 1, round);
	return 0;
      }
      index += height;
    }
  }
  return 0;
}
