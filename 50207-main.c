# include <stdio.h>
# include <stdlib.h>
# include "50207.h"
# define MAX 10
 
int main() {
  int size = 0;
  scanf("%d", &size);
 
  A *arrayA[size + 1];
  B *arrayB[size + 1];
  C *arrayC[size + 1];
 
  A matrixA[MAX];
  B matrixB[MAX];
  C matrixC[MAX];
  for (int n = 0; n < size; n++) {
    for (int i = 0; i < ROW; i++) 
      for (int j = 0; j < COL; j++) 
	scanf("%d", &matrixA[n][i][j]);
 
    for (int i = 0; i < COL; i++) 
      for (int j = 0; j < ROW; j++) 
	scanf("%d", &matrixB[n][i][j]);
 
    arrayA[n] = &(matrixA[n]);
    arrayB[n] = &(matrixB[n]);
    arrayC[n] = &(matrixC[n]);
  }
 
  arrayA[size] = NULL;
  arrayB[size] = NULL;
  arrayC[size] = NULL;
 
  multiplyMatrix(arrayA, arrayB, arrayC);
 
  for (int n = 0; n < size; n ++) {
    for (int i = 0; i < ROW; i ++) {
      for (int k = 0; k < ROW; k++) {
	printf("%d ", matrixC[n][i][k]);
      }
      printf("\n");
    }
    printf("\n");
  }
 
  return 0;
}
