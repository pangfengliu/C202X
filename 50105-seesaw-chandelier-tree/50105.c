#include <stdlib.h>
#include <stdint.h>
#include "construct.h"
 
Node *genNode(int value, Node *left, Node *right)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->left = left;
  node->right = right;
  node->value = value;
  return node;
}
 
int findSupport(int seesaw[], int start, int end)
{
  if (end - start < 2)
    return -1;

  int64_t moment = 0;
  int64_t weight = 0;
  for (int i = start; i <= end; i++) {
    weight += seesaw[i];
    moment += i * seesaw[i];
  }
  if (moment % weight == 0)
    return moment / weight;

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
 
  int balance = findSupport(seesaw, start, end); 
  if (balance == -1)
    return(genList(seesaw, N, start, end));
  else
    return(genNode(seesaw[balance], 
           genTree(seesaw, N, start, balance - 1),
           genTree(seesaw, N, balance + 1, end)));
 
}
 
Node *ConstructTree(int seesaw[], int N)
{
  return(genTree(seesaw, N, 0, N - 1));
}
