#include <stdio.h>

int min(int a, int b)
{
  return (a < b? a : b);
}

int max(int a, int b)
{
  return (a > b? a : b);
}

int gcd(int x, int y)		/* x > y */
{
  while (x % y != 0) {
    int remainder = x % y;
    x = y;
    y = remainder;
  }
  return y;
}

int lcm(int m, int n)
{
  return (m * n / gcd(max(m, n), min(m, n)));
}

int main()
{
  int a, b, c, d;
  while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
    printf("%d\n", lcm(lcm(lcm(a, b), c), d) / a);
  }
  return 0;
}
