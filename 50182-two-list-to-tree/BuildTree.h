typedef struct Node
{
          int val;
          struct Node *left, *right;
}Node;
Node* BuildTree(Node* list1, Node* list2);
