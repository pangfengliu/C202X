#include <stdio.h>

int main()
{
  int digit;
  int number = 0;
  int product = 1;
  
  scanf("%d", &digit);
#ifdef DEBUG
  printf("%d\n", digit);
#endif

  while (digit != 0) {
    if (digit >= 1 && digit <= 7)
      number = number * 10 + digit;
    else {			/* 8 */
      product *= number;
      number = 0;
    }
    
    scanf("%d", &digit);
#ifdef DEBUG
    printf("%d\n", digit);
#endif
  }
  product *= number;		/* the last one */
  printf("%d\n", product);
  return 0;
}
