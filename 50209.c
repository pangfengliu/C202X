#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
 
#define R 3
#define S 128
 
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

  return 0;
}
