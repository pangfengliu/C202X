#include <stdio.h>
#include <stdbool.h>

#define MAXR 500
#define MAXC 500


void printCandy(int candy[MAXR][MAXC], int R, int C)
{
  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++)
      printf("%d%c", candy[r][c], c == C - 1? '\n' : ' ');
}

bool in(int row, int col, int R, int C)
{
  return(row >= 0 && row < R && col >= 0 && col < C);
}

#define WAYS 6
#define OTHERS 2

void findSame(int candy[MAXR][MAXC], int row, int col, int R, int C)
{
  int startc = candy[row][col];
  int diff[WAYS][OTHERS][2] = {{{1, 0}, {0, 1}},
			       {{1, 0}, {1, 1}},
			       {{0, 1}, {1, 1}},
			       {{1, 0}, {2, 0}},
			       {{0, 1}, {0, 2}},
			       {{1, 0}, {1, -1}}};

  bool found = false;
  for (int w = 0; !found && w < WAYS; w++) {
    bool same3 = true;
    for (int other = 0; other < OTHERS; other++) {
      int r = row + diff[w][other][0];
      int c = col + diff[w][other][1];
      if (!in(r, c, R, C) || candy[r][c] != startc) 
	same3 = false;
    }

    if (same3) {
      candy[row][col] = 0;
      for (int other = 0; other < OTHERS; other++) {
	int r = row + diff[w][other][0];
	int c = col + diff[w][other][1];
	candy[r][c] = 0;
      }
      found = true;
    }
  }
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
