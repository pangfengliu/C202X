#include <stdio.h>
#include "50207.h"
 
void multiplyMatrix(void *arrayA, void *arrayB, void *arrayC)
{
  A **aptr = (A **)arrayA;
  B **bptr = (B **)arrayB;
  C **cptr = (C **)arrayC;

  for (; *aptr != NULL; aptr++, bptr++, cptr++) 
    for (int r = 0; r < ROW; r++)
      for (int c = 0; c < ROW; c++) {
	(**cptr)[r][c] = 0;
	for (int k = 0; k < COL; k++) {
	  (**cptr)[r][c] += (**aptr)[r][k] * (**bptr)[k][c];
	}
      }
}
