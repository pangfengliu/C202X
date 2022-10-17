#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
 
#define R 3
#define S 128
#define DIR 6

bool in(int row, int col, int length[R])
{
  return(row >= 0 && row < R && col >= 0 && col < length[row]);
}

int main()
{
  char *key[R] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

  char start[S];
  assert(scanf("%s", start) == 1);
  assert(strlen(start) == 1);
 
  int row, col;
  for (int i = 0; i < R; i++) {
    char *kptr = strchr(key[i], start[0]);
    if (kptr != NULL) {
      row = i;
      col = kptr - key[i];
    }
  }
  printf("%c\n", key[row][col]);

  int length[R];
  for (int i = 0; i < R; i++) {
    length[i] = strlen(key[i]);
#ifdef DEBUG
    printf("the length of string[%d] is %d\n", i, length[i]);
#endif
  }

    int dir;
  int move[DIR][2] = {{0, 1}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0}};
  while (scanf("%d", &dir) != EOF) {
    assert(dir >= 0 && dir < DIR);
    int newr = row + move[dir][0];
    int newc = col + move[dir][1];
    if (in(newr, newc, length)) {
      row = newr;
      col = newc;
      printf("%c\n", key[row][col]);
    }
  }

  return 0;
}
