#include <stdlib.h>
#include "construct.h"
 
Node *genNode(int value, Node *left, Node *right)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->left = left;
  node->right = right;
  node->value = value;
  return node;
}
 
int compare(const void *a, const void *b)
{
  int *aptr = (int *)a;
  int *bptr = (int *)b;
  if (*aptr < *bptr)
    return 1;
  else if (*aptr > *bptr)
    return -1;
  else
    return 0;
}
 
int findkth(int seesaw[], int start, int end)
{
  int length = end - start + 1;
  if (length < MAXLENGTH)
    return -1; 
 
  int temp[16385];
  for (int i = 0; i < length; i++)
    temp[i] = seesaw[i + start];
 
  qsort(temp, length, sizeof(int), compare);
  for (int i = start; i <= end; i++)
    if (seesaw[i] == temp[MAXLENGTH - 1])
      return i;
 
  return -1;
}
 
Node *genList(int seesaw[], int N, int start, int end)
{
  if (end < start)
    return NULL;
  return(genNode(seesaw[end], 
         genList(seesaw, N, start, end - 1),
         NULL));
}
Node *genTree(int seesaw[], int N, int start, int end)
{
  if (end < start)
    return NULL;
 
  int kthIndex = findkth(seesaw, start, end); 
  if (kthIndex == -1)
    return(genList(seesaw, N, start, end));
  else
    return(genNode(seesaw[kthIndex], 
           genTree(seesaw, N, start, kthIndex - 1),
           genTree(seesaw, N, kthIndex + 1, end)));
 
}
 
Node *ConstructTree(int seesaw[], int N)
{
  return(genTree(seesaw, N, 0, N - 1));
}
