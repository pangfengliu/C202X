#include <stdio.h>
#include <assert.h>
 
int max(int a, int b)
{
  return (a > b? a: b);
}

typedef struct Obj {
  int weight;
  int value;
} Object;

int maxValue(int W, int i, Object object[], int n)
{
  Object obj = object[i];
  if (i >= n)
    return 0;
  if (obj.weight > W)
    return maxValue(W, i + 1, object, n);
  else
    return (max(maxValue(W - obj.weight, i + 1, object, n) + obj.value,
		maxValue(W, i + 1, object, n)));
}
 
int main()
{
  int n, W;
  assert(scanf("%d%d", &n, &W) == 2);
  
  Object object[n];
  for (int i = 0; i < n; i++)
    assert(scanf("%d%d", &(object[i].weight), &(object[i].value)) == 2);
 
  printf("%d\n", maxValue(W, 0, object, n));
  return 0;
}
