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
    int row = round;
    int width = M - round + 1;
    printf("row %d from %d to %d\n", round, index, index + width - 1);
    index += width;

    if (round < N) {
      int col = round;
      int height = N - round;
      printf("col %d from %d to %d\n", round, index, index + height - 1);
      index += height;
    }
  }
  return 0;
}
