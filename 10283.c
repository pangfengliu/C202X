#include <stdio.h>

int main()
{
  int digit;
  int number = 0;
  int product = 1;
  int sum = 0;
    
  scanf("%d", &digit);
#ifdef DEBUG
  printf("%d\n", digit);
#endif

  while (digit != 0) {
    if (digit >= 1 && digit <= 7)
      number = number * 10 + digit;
    else {			/* 8 or 9 */
      product *= number;
      if (digit == 8) {
	sum += product;
	product = 1;
      }
      number = 0;
    }

    scanf("%d", &digit);
#ifdef DEBUG
    printf("%d\n", digit);
#endif
  }
  product *= number;		/* the last one */
  sum += product;
  printf("%d\n", sum);
  return 0;
}
