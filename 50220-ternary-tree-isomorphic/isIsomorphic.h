#include<stdbool.h>
struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *mid;
    struct TreeNode *right;
};
 
typedef struct TreeNode TreeNode;
 
bool isIsomorphic(TreeNode* root1, TreeNode* root2);
