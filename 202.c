#include <stdio.h>

int main()
{
  int a, b, c, d, e, f, g;
  scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
  
  int newb = (a < 0? a * c - b : a * c + b);
  int newf = (e < 0? e * g - f : e * g + f);
#ifdef DEBUG
  printf("%d %d\n", newb, newf);
#endif
  int divisor, dividend;
  switch (d) {			/* addition */
  case 0:
    divisor = c * g;
    dividend = g * newb + c * newf;
    break;
  }
#ifdef DEBUG
  printf("%d %d\n", divisor, dividend);
#endif
  int x = (dividend > 0? dividend : -dividend);
  int y = divisor;

  while (x % y != 0) {
    int remainder = x % y;
    x = y;
    y = remainder;
  }
  int factor = y;

  divisor /= factor;
  dividend /= factor;
#ifdef DEBUG
  printf("%d %d\n", divisor, dividend);
#endif
  int integer = dividend / divisor;
  dividend = dividend % divisor;
  
  if (dividend < 0)
    dividend = -dividend;

  if (dividend == 0)
    divisor = 1;

  printf("%d\n%d\n%d\n", integer, dividend, divisor);

  return 0;
}
