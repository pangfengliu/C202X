#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void merge(int A[], int B[], int* a[], int* b[])
{
  assert(a[0] == NULL && b[0] == NULL); /* one ellment */
  bool lastIsA;
  int **last = NULL;
  int indexA = 0, indexB = 0;
  if (A[indexA] < B[indexB]) {
    last = &(a[indexA]);
    lastIsA = true;
  } else {
    last = &(b[indexB]);
    lastIsA = false;
  }
  *last = lastIsA? &(B[indexB]) : &(A[indexA]);
}
