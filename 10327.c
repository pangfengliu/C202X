#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 105
#define MAXS (MAXN * MAXN)
#define MAXC 10

int max(int a, int b)
{
  return (a > b? a : b);
}

void getTower(int N, int tower[MAXN][MAXN][MAXN])
{
  for (int layer = 1; layer <= N; layer++)
    for (int row = 0; row < layer; row++)
      for (int col = 0; col < layer; col++)
	assert(scanf("%d", &(tower[row][col][N - layer])) == 1);
}

void computeHeight(int N, int height[MAXN][MAXN])
{
  for (int row = 0; row < N; row++)
    for (int col = 0; col < N; col++) {
      height[row][col] = N - max(row, col);
      printf("height [%d][%d] = %d\n", row, col, height[row][col]);
    }
}

void insert(int heap[MAXS][MAXC], int key, int S)
{
  int index = (77 * key + 2222) % S;
  for (int i = 0; i < MAXC; i++)
    if (heap[index][i] == 0) {
      heap[index][i] = key;
      return;
    }
  printf("no space found");
  exit(-1);
}

int main()
{
  int N, S, C;
  assert(scanf("%d%d%d", &N, &S, &C) == 3);
  assert(1 <= N && N <= MAXN);
  assert(1 <= S && S <= N * N);
  assert(1 <= C && C <= MAXC);

  int tower[MAXN][MAXN][MAXN];
  getTower(N, tower);

  int height[MAXN][MAXN];
  computeHeight(N, height);

  int heap[MAXS][MAXC] = {{0}}; 
  for (int row = 0; row < N; row++)
    for (int col = 0; col < N; col++) {
      printf("insert %d into heap\n", tower[row][col][height[row][col] - 1]);
      insert(heap, tower[row][col][height[row][col] - 1], S);
    }

  for (int s = 0; s < S; s++) {
    for (int c = 0; c < C; c++)
      if (heap[s][c] > 0)
	printf("%d ", heap[s][c]);
    printf("\n");
  }
  
  return 0;
}
