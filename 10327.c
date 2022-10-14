#include <stdio.h>
#include <assert.h>

#define MAXN 105
#define MAXS (MAXN * MAXN)
#define MAXC 10

int main()
{
  int N, S, C;
  assert(scanf("%d%d%d", &N, &S, &C) == 3);
  assert(1 <= N && N <= MAXN);
  assert(1 <= S && S <= N * N);
  assert(1 <= C && C <= MAXC);

  int tower[MAXN][MAXN][MAXN];
  for (int layer = 1; layer <= N; layer++)
    for (int row = 0; row < layer; row++)
      for (int col = 0; col < layer; col++)
	assert(scanf("%d", &(tower[row][col][N - layer - 1])) == 1);

  return 0;
}
  

      
