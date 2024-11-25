#include <stdio.h>
#include <stdlib.h>

int *foo()
{
#ifdef MALLOC
  return (int *)(malloc(sizeof(int)));
#else
  int j = 0;
  return &j;
#endif
}
int main()
{
  int i = 2;
  int *iptr = foo();
  (*iptr) = 8;
  printf("%d\n", *iptr);
  return 0;
}
