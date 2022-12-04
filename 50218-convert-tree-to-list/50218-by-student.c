# include<stdio.h>
# include<stdlib.h>
# include<assert.h>
# include "treeToList.h"
 
List rootList(TreeNode *root){
    List list;
    list.head = list.tail = root;
    list.head->right = list.tail->right = NULL;
    return list;
}
 
List concat(List a, List b){
    if(a.head == NULL)
        return b;
    else if(b.head == NULL)
        return a;
    List c;
    c.head = a.head;
    a.tail->left = b.head;
    c.tail = b.tail;
    return c;
}
 
List treeToListFunc(TreeNode *root){
    if(root == NULL){
        List nothing;
        nothing.head = nothing.tail = NULL;
        return nothing;
    }
 
    List left = treeToListFunc(root->left);
    List right = treeToListFunc(root->right);
 
    if(root->value % 2 == 0){
        return concat(rootList(root), concat(left, right));
    }else{
        return concat(rootList(root), concat(right, left));
    }
}
