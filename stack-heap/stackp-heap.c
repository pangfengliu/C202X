#include <stdio.h>

int *foo()
{
  int j = 0;
  return &j; 
}
int main()
{
  int i;
  int *iptr = foo();
  *iptr += 8;
  return 0;
}
