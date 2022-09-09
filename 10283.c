#include <stdio.h>

int main()
{
  int digit;
  scanf("%d", &digit);
  printf("%d\n", digit);
  while (digit != 0) {
    scanf("%d", &digit);
    printf("%d\n", digit);
  }
  return 0;
}
