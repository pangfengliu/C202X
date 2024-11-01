#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#define W 64
#define K 75000

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

int countSeg(int l, int n)
{
  return (l >= n? l - n + 1 : 0);
}

int countRow(bool bits[W], int n)
{
  int count = 0;
  int len = bits[0]? 1 : 0;
  
  for (int i = 1; i < W; i++)
    if (bits[i])
      len++;
    else {
      count += countSeg(len, n);
      len = 0;
    }
  count += countSeg(len, n);
  return count;
}

int main()
{
  int n;
  uint64_t ull;
  bool bits[W];
  
  scanf("%d", &n);
  int row = 0;
  
  for (int i = 0; i < K; i++) {
    assert(scanf("%lu", &ull) == 1);
    getBits(ull, bits);
    row += countRow(bits, n); 
  }
  printf("%d\n", row);
  
  return 0;
}
