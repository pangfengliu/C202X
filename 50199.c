#include <stdio.h>
#include <stdbool.h>

#define MAXR 500
#define MAXC 500

#define WAYS 6
#define OTHERS 2

void printCandy(int candy[MAXR][MAXC], int R, int C)
{
  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++)
      printf("%d%c", candy[r][c], c == C - 1? '\n' : ' ');
}

void findSame(int candy[MAXR][MAXC], int row, int col, int R, int C)
{
}


void remove3(int candy[MAXR][MAXC], int R, int C)
{
  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++)
      if (candy[r][c] != 0) {
	findSame(candy, r, c, R, C);
      }
}


int main()
{
  int R, C;
  scanf("%d%d", &R, &C);
  
  int candy[MAXR][MAXC];
  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++)
      scanf("%d", &(candy[r][c]));

  remove3(candy, R, C);
  printCandy(candy, R, C);
  return 0;
}
