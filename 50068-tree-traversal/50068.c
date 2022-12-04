#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
 
void traversal(Node *root, int N, int command[])
{
  Node *path[1000];
  path[0] = root;
  int current = 0;
 
  Node *leftChild, *rightChild, *parent, *sibling;
 
  for (int i = 0; i < N; i++) {
    switch (command[i]) {
    case 0:
      printf("%d\n", path[current]->label);
      return;
    case 1:
      printf("%d\n", path[current]->label);
      break;
    case 2:
      current--;
      break;
    case 3:
      leftChild = path[current]->left;
      if (leftChild == NULL) {
    printf("%d\n", path[current]->label);
    return;
      } else {
    current++;
    path[current] = leftChild;
      }
      break;
    case 4:
      rightChild = path[current]->right;
      if (rightChild == NULL) {
    printf("%d\n", path[current]->label);
    return;
      } else {
    current++;
    path[current] = rightChild;
      }
      break;
    case 5:
      parent = path[current - 1];
      if (parent->left == path[current]) /* left */
    sibling = parent->right;
      else
    sibling = parent->left;
      if (sibling == NULL) {
    printf("%d\n", path[current]->label);
    return;
      } else
    path[current] = sibling;
      break;
    default:
      printf("invalid command %d\n", command[i]);
      exit(-1);
    }
  }
}
