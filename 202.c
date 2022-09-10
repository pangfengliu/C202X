#include <stdio.h>

int main()
{
  int a, b, c, d, e, f, g;
  scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
  
  int newb = (a < 0? a * c - b : a * c + b);
  int newf = (e < 0? e * g - f : e * g + f);

  printf("%d %d\n", newb, newf);

  return 0;
}
