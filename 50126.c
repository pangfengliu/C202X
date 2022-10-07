#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void merge(int A[], int B[], int* a[], int* b[])
{
#ifdef SUBTASK1
  assert(a[0] == NULL && b[0] == NULL); /* one ellment */
#endif
  bool lastIsA;
  int **last = NULL;
  int indexA = 0, indexB = 0;

  do {
    if (A[indexA] < B[indexB]) {
      if (last == NULL)
	last = &(a[indexA]);
      else {
	(*last) = &(A[indexA]);
	last = &(a[indexA]);
      }
      indexA++;
      lastIsA = true;
    } else {
      if (last == NULL)
	last = &(b[indexB]);
      else {
	(*last) = &(B[indexB]);
	last = &(b[indexB]);
      }
      indexB++;
      lastIsA = false;
    }
  } while (*last != NULL);
  *last = lastIsA? &(B[indexB]) : &(A[indexA]);
}
