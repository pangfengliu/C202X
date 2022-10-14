#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAXN 105
#define MAXS (MAXN * MAXN)
#define MAXC 10

#define KEY 0
#define INDEX 1

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

int f(int key, int S)
{
  return ((77 * key + 2222) % S);
}

void insert(int heap[MAXS][MAXC][2], int key, int S, int tindex)
{
  int hindex = f(key, S);
  for (int i = 0; i < MAXC; i++)
    if (heap[hindex][i][KEY] == 0) {
      heap[hindex][i][KEY] = key;
      heap[hindex][i][INDEX] = tindex;
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

  
  int heap[MAXS][MAXC][2] = {{{0}}};
  int tindex = 0;
  bool paired = false;
  int minfex1, mindex2;
  for (int row = 0; row < N; row++)
    for (int col = 0; col < N; col++, tindex++) {
      int key = tower[row][col][height[row][col] - 1];
      printf("insert %d into heap\n", key);
      if ((mtindex1 = match(heap, key, S, tindex)) == -1)
	insert(heap, key, S, tindex);
      else {
	paired = true;
	mtindex2 = tindex;
      }
    }

  for (int s = 0; s < S; s++) {
    for (int c = 0; c < C; c++)
      if (heap[s][c][KEY] > 0)
	printf("(%d %d)", heap[s][c][KEY], heap[s][c][INDEX]);
    printf("\n");
  }

  printf("mtindex1 %d mtindex2 %d paired %d\n", mtindex1, mtindex2, paired);  
  return 0;
}
