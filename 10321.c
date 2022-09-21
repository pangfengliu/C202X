#include <stdio.h>

int min(int a, int b)
{
  return (a < b? a : b);
}

int max(int a, int b)
{
  return (a > b? a : b);
}

int lcm(int m, int n)
{
  int x = max(m, n);
  int y = min(m, n);  
  
  while (x % y != 0) {
    int remainder = x % y;
    x = y;
    y = remainder;
  }
  return (m * n / y);
}

int main()
{
  int a, b, c, d;
  while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
    printf("%d\n", lcm(lcm(lcm(a, b), c), d) / a);
  }
  return 0;
}
