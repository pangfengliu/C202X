#include <stdio.h>
#include <assert.h>
 
#define MAXL 100000
 
void printKeys(int keys[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d%c", keys[i], (i == n - 1)? '\n' : ' ');
}
 
void mergeSort(int keys[], int n)
{
  printKeys(keys, n);
  if (n == 1) 
    return;
  int leftLength = n / 2;
  int rightLength = n - leftLength;
  int left[leftLength];
  int right[rightLength];
  for (int i = 0; i < leftLength; i++)
    left[i] = keys[i];
  for (int i = 0; i < rightLength; i++)
    right[i] = keys[leftLength + i];
 
  mergeSort(left, leftLength);
  mergeSort(right, rightLength);
 
  int leftIndex = 0;
  int rightIndex = 0;
  int index = 0;
  while ((leftIndex < leftLength) || (rightIndex < rightLength)) 
    if (rightIndex == rightLength ||
    (leftIndex < leftLength && left[leftIndex] < right[rightIndex]))
      keys[index++] = left[leftIndex++];
    else
      keys[index++] = right[rightIndex++];
 
  assert(leftIndex == leftLength && rightIndex == rightLength);
  printKeys(keys, n);
}  
 
int main()
{
  int index = 0;
  int keys[MAXL];
 
  while (scanf("%d", &(keys[index])) != EOF) 
    index++;
 
  mergeSort(keys, index);
  return 0;
}
