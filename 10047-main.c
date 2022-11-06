#include <stdio.h>
#include <assert.h>
#include "10047.h"

#define MAXN 128

int main() {
  int n, K, S;
  while (scanf("%d%d%d", &n, &K, &S) == 3) {
    int number[MAXN];
    for (int i = 0; i < n; i++)
      assert(scanf("%d", &number[i]) == 1);
    printf("%d\n", subset(number, n, K, S));
  }
  return 0;
}
