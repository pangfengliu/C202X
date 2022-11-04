#include <stdio.h>
#include <assert.h>
 
#define MAXL 100000
 
void printKeys(int keys[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d%c", keys[i], (i == n - 1)? '\n' : ' ');
}
 
void merge(int left[], int leftIndex, int leftLength,
       int right[], int rightIndex, int rightLength,
       int keys[], int index)
{
  if ((leftIndex == leftLength) && (rightIndex == rightLength))
    return;
  if (rightIndex == rightLength ||
      (leftIndex < leftLength && left[leftIndex] < right[rightIndex])) 
    keys[index++] = left[leftIndex++];
  else
    keys[index++] = right[rightIndex++];
 
  merge(left, leftIndex, leftLength, right, rightIndex, rightLength, keys, index);
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
 
  merge(left, 0, leftLength, right, 0, rightLength, keys, 0);
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
