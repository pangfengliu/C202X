#include <stdio.h>
 
void chasing(int **A[], int a, int *B[], int b, int C[], int c)
{
  for (int i = 0; i < a; i++)
    A[i] = NULL;
  for (int i = 0; i < b; i++)
    B[i] = NULL;
  char line[100];
  while (fgets(line, 100, stdin) != NULL) {
    int index1, index2;
    char name1[100], name2[100];
    printf("%d\n", 1);
    sscanf(line, "%s%d%s%d", name1, &index1, name2, &index2);
    if (name1[0] == 'A')
      A[index1] = &(B[index2]);
    if (name1[0] == 'B')
      B[index1] = &(C[index2]);
  }
}
