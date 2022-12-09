#include "isIsomorphic.h"
#include <stdlib.h>
#include <assert.h>
 
bool isIsomorphic(TreeNode* root1, TreeNode* root2) {
  if (root1 == NULL && root2 == NULL) return true;
  if (root1 == NULL || root2 == NULL) return false;
 
  TreeNode* subTrees1[3] = {root1->left, root1->mid, root1->right};
  TreeNode* subTrees2[3] = {root2->left, root2->mid, root2->right};
  bool subTree2Mapped[3] = {false};
 
  for (int i = 0; i < 3; i++) {
    bool mapped = false;
    for (int j = 0; j < 3; j++) {
      if (subTree2Mapped[j] == false && isIsomorphic(subTrees1[i], subTrees2[j])) {
	mapped = true;
	subTree2Mapped[j] = true;
	break;
      }
    }
    if (mapped == false) return false;
  }
 
  return true;
}
