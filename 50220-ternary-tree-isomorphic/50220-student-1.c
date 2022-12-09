#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "isIsomorphic.h"
bool isIsomorphic(TreeNode *root1, TreeNode *root2)
{
  if (root1 == NULL && root2 == NULL)
    return true;
  if (root1 == NULL || root2 == NULL)
    return false;
  bool ll = isIsomorphic(root1->left, root2->left);
  bool mm = isIsomorphic(root1->mid, root2->mid);
  bool rr = isIsomorphic(root1->right, root2->right);
  bool lm = isIsomorphic(root1->left, root2->mid);
  bool lr = isIsomorphic(root1->left, root2->right);
  bool ml = isIsomorphic(root1->mid, root2->left);
  bool mr = isIsomorphic(root1->mid, root2->right);
  bool rl = isIsomorphic(root1->right, root2->left);
  bool rm = isIsomorphic(root1->right, root2->mid);
  return (ll && mm && rr) || (ll && mr && rm) || 
    (mm && lr && rl) || (rr && lm && ml) ||
    (lr && ml && rm) || (lm && mr && rl);
}
