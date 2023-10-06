#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "loops.h"

#define MAXN 1000000

int main()
{
  int N;
  int A[MAXN];
  int *B[MAXN];

  assert(scanf("%d", &N) == 1);
  for (int i = 0; i < N; i++)
    assert(scanf("%d", A + i) == 1);
  
  for (int i = 0, ptr; i < N; i++) {
    assert(scanf("%d", &ptr) == 1);
    B[i] = A + ptr;
  }
  
  int ans[4];
  loops(N, A, B, ans);
  for(int i = 0; i < 4; i++)
    printf("%d\n", ans[i]);
  
  return 0;
}
