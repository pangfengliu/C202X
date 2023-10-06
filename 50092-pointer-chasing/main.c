#include <stdio.h>
#include "chasing.h"
int main() {
  int a = 5, b = 4, c = 3;
  int **A[5] = {}, *B[4] = {}, C[3] = {2, 1, 4};
  chasing(A, a, B, b, C, c);
 
  int **ansA[5] = {} ,*ansB[4] = {};
  for (int i = 0; i < a; i++)
    ansA[i] = NULL;
  for (int i = 0; i < b; i++)
    ansB[i] = NULL;
  ansA[2] = &B[1], ansA[3] = &B[0], ansB[1] = &C[1], ansB[2] = &C[0];
  /*Check A*/
  for (int i = 0; i < a; i++)
    if (A[i] != ansA[i] )
      printf("A[%d] wrong answer!\n", i);
 
  /*Check B*/
  for (int i = 0; i < b; i++)
    if (B[i] != ansB[i] )
      printf("B[%d] wrong answer!\n", i);
  return 0;
}
