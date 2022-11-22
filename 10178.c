#include <stdio.h>

#define N 512

int insert(int *ptr, int *ptrTable[], int object[], int frequency[], 
	   int currentCount)
{
  for (int i = 0; i < currentCount; i++)
    if (ptr == ptrTable[i]) {
      frequency[i]++;
      return currentCount;
    }
  /* not found */
  ptrTable[currentCount] = ptr;
  frequency[currentCount] = 1;
  object[currentCount] = *ptr;
  return currentCount + 1;
}

void count(int **p[])
{
  int ***firstLevel = p;
  int count = 0;
  int frequency[N] = {0};
  int object[N];
  int *thirdLevelPtrTable[N];

  while (*firstLevel != NULL) {
    int *thirdLevel = **firstLevel;
    count = insert(thirdLevel, thirdLevelPtrTable, object, frequency, count);
    printf("%d\n", *thirdLevel);
    firstLevel++;
  }
  for (int i = 0; i < count; i++)
    printf("%d %d\n", object[i], frequency[i]);
}
