#include <stdio.h>
 
#define MAXN 100
#define GREEN 0
 
int main()
{
  int cube[MAXN][MAXN][MAXN];
  int n, m;
  scanf("%d%d", &n, &m);
 
  int value = 0;
  for (int x = 0; x < n; x++)
    for (int y = 0; y < n; y++)
      for (int z = 0; z < n; z++, value++)
	cube[x][y][z] = value;
 
  for (int i = 0; i < m; i++) {
    int plate[MAXN][MAXN];
    int type, index;
    scanf("%d%d", &type, &index);
    switch(type) {
    case GREEN:
      for (int r = 0; r < n; r++)
	for (int c = 0; c < n; c++)
	  plate[c][n - r - 1] = cube[index][r][c];
 
      for (int r = 0; r < n; r++)
	for (int c = 0; c < n; c++)
	  cube[index][r][c] = plate[r][c];
      break;
    }
 
  }
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      for (int z = 0; z < n; z++)
	printf("%d ", cube[x][y][z]);
      printf("\n");
    }
  }
  return 0;
}
