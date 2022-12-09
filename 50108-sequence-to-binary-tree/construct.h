#ifndef CONSTRUCT
#define CONSTRUCT
typedef struct node{
    int value;
    struct node *left, *right;
} Node;
Node *ConstructTree(int sequence[], int N);
#endif
