#include <stdio.h>
#include <assert.h>
 
#include "BuildTree.h"
 
typedef struct list {
  Node *ptr;
  int length;
} List;
 
int listLength(Node *ptr)
{
  int len = 0;
  while (ptr != NULL) {
    ptr = ptr->left;
    len++;
  }
  return len;
}
 
Node *skipHalf(Node *head, int n) 
{
  assert((head != NULL) && (n > 0));
 
  for (int i = 0; i < n - 1; i++)
    head = head->left;
 
  Node *second = head->left;
  head->left = NULL;
  return second;
}
 
 
int secondHalfLength(int n)
{
  return n / 2;
}
 
int firstHalfLength(int n)
{
  return (n - secondHalfLength(n));
}
 
 
void cut(List list, List *first, List *second)
{
  List none = {NULL, 0};
  if (list.ptr == NULL) {
    *first = *second = none;
    return;
  }
 
  first->ptr = list.ptr;
  first->length = firstHalfLength(list.length);
 
  second->ptr = skipHalf(list.ptr, first->length);
  second->length = secondHalfLength(list.length);
 
  return;
}
 
Node *BuildListTree(List list1, List list2)
{
  if (list1.ptr == NULL && list2.ptr == NULL)
    return NULL;
 
  if (list1.ptr == NULL)
    return list2.ptr;
  if (list2.ptr == NULL)
    return list1.ptr;
 
  Node *root;
  if (list1.ptr->val < list2.ptr->val) {
    root = list1.ptr;
    list1.ptr = list1.ptr->left;
    list1.length--;
  } else {
    root = list2.ptr;
    list2.ptr = list2.ptr->left;
    list2.length--;
  }
#ifdef DEBUG
  printf("root %d\n", root->val);
#endif
 
  List list1first, list1second;
  List list2first, list2second;
  cut(list1, &list1first, &list1second); 
  cut(list2, &list2first, &list2second); 
  root->left = BuildListTree(list1first, list2first);
  root->right = BuildListTree(list1second, list2second);
  return root;
}
 
Node *BuildTree(Node* lst1, Node* lst2)
{
  int lst1length = listLength(lst1);
  int lst2length = listLength(lst2);
  List list1 = {lst1, lst1length};
  List list2 = {lst2, lst2length};
 
  return BuildListTree(list1, list2);
}
