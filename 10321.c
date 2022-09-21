#include <stdio.h>

int main()
{
  int a, b, c, d;
  while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
    printf("%d %d %d %d\n", a, b, c, d);

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
    printf("ablcm = %d\n", ablcm);
  }
  
  return 0;
}
