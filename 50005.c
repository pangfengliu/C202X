#include <stdio.h>
 
int main()
{
  int n, k, m, d;
  scanf("%d%d%d%d", &n, &k, &m, &d);

  int matrix[10][10];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &(matrix[i][j]));

  int pattern[10][10];
  for (int i = 0; i < k; i++)
    for (int j = 0; j < k; j++)
      scanf("%d", &(pattern[i][j]));
 
  int matchi, matchj;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == pattern[0][0]) {
	matchi = i;
	matchj = j;
      }
    }
 
  printf("%d %d\n", matchi, matchj);
  return 0;
}
