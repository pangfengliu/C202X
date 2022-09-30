#include <stdio.h>
#include <assert.h>

#define SIZE 10

int matchNum(int i, int j, int k,
	     int pattern[SIZE][SIZE], int matrix[SIZE][SIZE])
{
  int match = 0;
  for (int x = 0; x < k; x++)
    for (int y = 0; y < k ; y++)
      if (pattern[x][y] == matrix[i + x][j + y])
	match++;
  return match;
}

int main()
{
  int n, k, m, d;
  assert(scanf("%d%d%d%d", &n, &k, &m, &d) == 4);

  int matrix[SIZE][SIZE];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      assert(scanf("%d", &(matrix[i][j])) == 1);

  int pattern[SIZE][SIZE];
  for (int i = 0; i < k; i++)
    for (int j = 0; j < k; j++)
      assert(scanf("%d", &(pattern[i][j])) == 1);
 
  int matchi, matchj;

  for (int i = 0; i < n - k + 1; i++)
    for (int j = 0; j < n - k + 1; j++) {
      if (matchNum(i, j, k, pattern, matrix) >= k * k - m) {
	matchi = i;
	matchj = j;
      }
    }
 
  printf("%d %d\n", matchi, matchj);
  return 0;
}
