#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#define W 64
#define K 75000

void getBits(uint64_t ull, bool bits[W])
{
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
  int row = 0, col = 0, colLen[W], diag = 0, diagLen[W];
  
  for (int r = 0; r < K; r++) {
    assert(scanf("%lu", &ull) == 1);
    getBits(ull, bits);
    row += countRow(bits, n);

    if (r == 0) 
      for (int c = 0; c < W; c++) 
	colLen[c] = diagLen[c] = (bits[c]? 1 : 0);
    else {
      /* col */
      for (int c = 0; c < W; c++) 
	if (bits[c])
	  colLen[c]++;
	else {
	  col += countSeg(colLen[c], n);
	  colLen[c] = 0;
	}

      /* diag */
      diag += countSeg(diagLen[0], n);
      for (int c = 0; c < W - 1; c++) 
	if (bits[c])
	  diagLen[c] = diagLen[c + 1] + 1;
	else {
	  diag += countSeg(diagLen[c + 1], n);
	  diagLen[c] = 0;
	}
      diagLen[W - 1] = bits[W - 1]? 1 : 0;
    }
  }
  for (int c = 0; c < W; c++) {
    col += countSeg(colLen[c], n);
    diag += countSeg(diagLen[c], n);
  }
    
  printf("%d\n", row);
  printf("%d\n", col);
  printf("%d\n", diag);
  
  return 0;
}
