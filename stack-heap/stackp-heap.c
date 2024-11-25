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
  return 0;
}
