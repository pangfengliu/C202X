#include <stdio.h>
 
int **first[200];
int *second[1000000];
 
int ***constructTable(int A[], int B[])
{
  int ***firstPtr = first;
  int **secondPtr = second;
  int *Bptr = B;
 
  for (int i = 0; A[i] != 0; i++) {
    *firstPtr++ = secondPtr;
    for (int j = 0; j < A[i]; j++) {
      *secondPtr++ = Bptr;
      while (*Bptr != 0)
	Bptr++;
      Bptr++;            /* skip 0 */
    }
    *secondPtr++ = NULL;
#ifdef DEBUG
    printf("%d\n", A[i]);
#endif
  }
  *firstPtr = NULL;
  return first;
}
