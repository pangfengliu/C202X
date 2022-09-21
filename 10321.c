#include <stdio.h>

int main()
{
  int a, b, c, d;
  while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
#ifdef DEBUG
    printf("%d %d %d %d\n", a, b, c, d);
#endif
    int ablcm;
    {
      int m = a;
      int n = b;
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
      ablcm = m * n / y;
    }
#ifdef DEBUG
    printf("ablcm = %d\n", ablcm);
#endif
    int abclcm;
    {
      int m = ablcm;
      int n = c;
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
      abclcm = m * n / y;
    }
#ifdef DEBUG
    printf("abclcm = %d\n", abclcm);
#endif
  
    int abcdlcm;
    {
      int m = abclcm;
      int n = d;
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
      abcdlcm = m * n / y;
    }
#ifdef DEBUG
    printf("abcdlcm = %d\n", abcdlcm);
#endif
    printf("%d\n", abcdlcm / a);
  }

  return 0;
}
