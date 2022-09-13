#include <stdio.h>

int main()
{
  int k;
  scanf("%d", &k);
  for (int i = 1; i <= 9; i++)
    for (int j = ((i - k) < 0? 0 : i - k); j <= (i + k > 9? 9 : i + k); j++)
      printf("%d%d\n", i, j);
  return 0;
}
