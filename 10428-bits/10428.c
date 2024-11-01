#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define W 64

void getBits(uint64_t ull, bool bits[W])
{
#ifdef DEBUG
  printf("%016lx\n", ull);
#endif
  for (int i = 0; i < W; i++) {
    bits[i] = ull & 1;
    ull >>= 1;
  }
}

int main()
{
  int n;
  uint64_t ull;
  bool bits[W];
  
  scanf("%d", &n);
  scanf("%lu", &ull);

  getBits(ull, bits);
#ifdef DEBUG
  for (int i = W - 1; i >= 0; i--)
    printf("%d", bits[i] ? 1 : 0);
  printf("\n");
#endif
  return 0;
}
