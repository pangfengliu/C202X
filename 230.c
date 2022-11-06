#include <stdio.h>
#include <assert.h>
 
int max(int a, int b)
{
  return (a > b? a: b);
}
 
int maxValue(int W, int i, int weight[], int value[], int n)
{
  if (i >= n)
    return 0;
  if (weight[i] > W)
    return maxValue(W, i + 1, weight, value, n);
  else
    return (max(maxValue(W - weight[i], i + 1, weight, value, n) + value[i],
        maxValue(W, i + 1, weight, value, n)));
}
 
int main()
{
  int n, W;
  assert(scanf("%d%d", &n, &W) == 2);
  int weight[n], value[n];
  for (int i = 0; i < n; i++)
    assert(scanf("%d%d", &weight[i], &value[i]) == 2);
 
  printf("%d\n", maxValue(W, 0, weight, value, n));
  return 0;
}
