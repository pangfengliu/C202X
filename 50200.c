#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define MAXR 500
#define MAXC 500
#define DIR 4

#define STONE 0
#define QUEEN 1
#define BISHOP 2
#define ROOK 3

bool in(int row, int col, int R, int C)
{
  return (row >= 0 && row < R && col >= 0 && col < C);
}

void attack(bool stone[MAXR][MAXC], int row, int col, int dr, int dc,
	    int R, int C)
{
  int r = row + dr;
  int c = col + dc;
  while (in(r, c, R, C) && !stone[r][c]) {
    stone[r][c] = true;
    r += dr;
    c += dc;
  }
}

void rookAttack(bool stone[MAXR][MAXC], int row, int col, int R, int C)
{
  int dr[] = {0, 0, 1, -1};
  int dc[] = {1, -1, 0, 0};
  for (int i = 0; i < DIR; i++)
    attack(stone, row, col, dr[i], dc[i], R, C);
  stone[row][col] = true;
}

void bishopAttack(bool stone[MAXR][MAXC], int row, int col, int R, int C)
{
  int dr[] = {1, -1, 1, -1};
  int dc[] = {1, -1, -1, 1};
  for (int i = 0; i < DIR; i++)
    attack(stone, row, col, dr[i], dc[i], R, C);
  stone[row][col] = true;
}

void queenAttack(bool stone[MAXR][MAXC], int row, int col, int R, int C)
{
  rookAttack(stone, row, col, R, C);
  bishopAttack(stone, row, col, R, C);
}

int main()
{
  int R, C;
  assert(scanf("%d%d", &R, &C) == 2);

  bool stone[MAXR][MAXC] = {{false}};
  int type, row, col;
  while (scanf("%d%d%d", &type, &col, &row) != EOF) {
    switch (type) {
    case STONE:
      stone[row][col] = true;
      break;
    case ROOK:
      rookAttack(stone, row, col, R, C);
      break;
    case BISHOP:
      bishopAttack(stone, row, col, R, C);
      break;
    case QUEEN:
      queenAttack(stone, row, col, R, C);
      break;
    }
  }

  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++)
      printf("%d%c", stone[r][c], (c == C - 1? '\n' : ' '));

  return 0;
}
