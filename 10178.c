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

void sort(int frequency[], int object[], int count)
{
  for (int i = count - 2; i >= 0; i--)
    for (int j = 0; j <= i; j++)
      if (frequency[j] > frequency[j + 1] || 
      (frequency[j] == frequency[j + 1] && object[j] >= object[j + 1])) {
    int temp = frequency[j];
    frequency[j] = frequency[j + 1];
    frequency[j + 1] = temp;
    temp = object[j];
    object[j] = object[j + 1];
    object[j + 1] = temp;
      }
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

  sort(frequency, object, count);
  for (int i = 0; i < count; i++)
    printf("%d %d\n", object[i], frequency[i]);
}
