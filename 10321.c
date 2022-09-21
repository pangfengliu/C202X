#include <stdio.h>

int lcm(int m, int n)
{
  int x, y;
  
  if (m > n) {
    x = m;
    y = n;
  } else {
    x = n;
    y = m;
  }
  
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
    int ablcm = lcm(a, b);
    int abclcm = lcm(ablcm, c);
    int abcdlcm = lcm(abclcm, d);
    printf("%d\n", abcdlcm / a);
  }
  return 0;
}
