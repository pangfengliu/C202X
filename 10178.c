#include <stdio.h>

void count(int **p[])
{
  int ***firstLevel = p;
  while (*firstLevel != NULL) {
    int key = ***firstLevel;
    printf("%d\n", key);
    firstLevel++;
  }
}
