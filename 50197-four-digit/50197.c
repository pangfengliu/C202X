#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= 9; i++)
    for (int j = ((i - n) < 0? 0 : i - n); j <= (i + n > 9? 9 : i + n); j++)
      for (int k = ((j - n) < 0? 0 : j - n); k <= (j + n > 9? 9 : j + n); k++)
	for (int l = ((k - n) < 0? 0 : k - n); l <= (k + n > 9? 9 : k + n); l++)
	  printf("%d%d%d%d\n", i, j, k, l);
  return 0;
}
