#include <stdio.h>
#include <assert.h>
 
#define MAXN 100000
#define W 3
 
int maxPoint(int a[], int b[])
{
  int maxv = a[0] + b[0], maxi;
  for (int i = 1; i < W; i++)
    if (a[i] + b[i] > maxv) {
      maxv = a[i] + b[i];
      maxi = i;
    }
  return maxi;
}
 
#define P 4
 
int main()
{
  int n;
  assert(scanf("%d", &n) == 1);
 
  int bottom[P][W] = {{-1, 0, 1}, {0, 0, -1}, {0, 0, 0}, {-1, 0, -1}};
  int extra[P][W][W] = {{{1, 1, 0}, {2, 2, 1}, {2, 2, 1}},
            {{1, 2, 2}, {1, 2, 2}, {0, 1, 1}},
            {{1, 2, 1}, {1, 2, 1}, {1, 2, 1}},
            {{1, 1, 1}, {2, 2, 2}, {1, 1, 1}}};
  int col, type;
  int height[MAXN] = {0};
  while (scanf("%d%d", &col, &type) != EOF) {
    int stuck = maxPoint(&(height[col]), bottom[type]);
    int stuckH = height[col + stuck];
    for (int i = 0; i < W; i++)
      height[col + i] = stuckH + extra[type][stuck][i];
  }
  for (int i = 0; i < n; i++)
    printf("%d%c", height[i], (i == n - 1)? '\n' : ' ');
  return 0;
}
