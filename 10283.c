#include <stdio.h>

int main()
{
  int digit;
  int number = 0;
  scanf("%d", &digit);
#ifdef DEBUG
  printf("%d\n", digit);
#endif
  while (digit != 0) {
    if (digit >= 1 && digit <= 7)
      number = number * 10 + digit;
    scanf("%d", &digit);
#ifdef DEBUG
    printf("%d\n", digit);
#endif
  }
  printf("%d\n", number);
  return 0;
}
