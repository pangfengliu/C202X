#include <stdio.h>
#include "BuildTree.h"
#define MAXN 100
 
void tree_print(Node* root){
  if(root == NULL) return;
  printf("%d ", root->val);
  tree_print(root->left);
  tree_print(root->right);
}
 
int main()
{
  int i, n, m, num;
  Node l1[MAXN], l2[MAXN];
 
  scanf("%d%d", &n, &m);
  for(i = 0; i < n; i++){
    scanf("%d", &num);
    l1[i].val = num;
    l1[i].left = &l1[i+1];
    l1[i].right = NULL;
  }
  l1[n-1].left = NULL;
  Node *root1 = &l1[0];
  for(i = 0; i < m; i++){
    scanf("%d", &num);
    l2[i].val = num;
    l2[i].left = &l2[i+1];
    l2[i].right = NULL;
  }
  l2[m-1].left = NULL;
  Node *root2 = &l2[0];
 
  Node *ans = BuildTree(root1, root2);
  tree_print(ans);
  printf("\n");
 
  return 0;
}
