#include <stdio.h>
#include "construct.h"
#include "assert.h"

#define MAXN 16384
 
int sequence[MAXN];
 
void PrintTree( Node *root )
{
  if (root == NULL)
    return;
  printf("%d\n", root->value);
  PrintTree(root->left);
  PrintTree(root->right);
  return;
}

int main()
{
  int N;
  assert(scanf("%d", &N) == 1);
  for (int i = 0; i < N; i++)
    assert(scanf("%d", &sequence[i]) == 1);
  Node *tree = ConstructTree(sequence, N);
  PrintTree(tree);
  return 0;
}
