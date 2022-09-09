#include <stdio.h>

int main()
{
  int digit;
  int number = 0;
  scanf("%d", &digit);
  printf("%d\n", digit);
  while (digit != 0) {
    if (digit >= 1 && digit <= 7)
      number = number * 10 + digit;
    scanf("%d", &digit);
    printf("%d\n", digit);
  }
  printf("%d\n", number);
  return 0;
}
