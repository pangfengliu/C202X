#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#define BITS 64

int main()
{
  int n, m;
  assert(scanf("%d%d", &n, &m) == 2);
  assert(n >= 1 && n <= BITS);

  uint64_t neighbor[BITS] = {0};
  uint64_t hasNeighbor = 0;

  uint64_t bit[n];
  for (int i = 0; i < n; i++)
    bit[i] = ((uint64_t)(1) << i);
  
  for (int i = 0; i < m; i++) {
    int v, w;
    assert(scanf("%d%d", &v, &w) == 2);
    neighbor[v] |= bit[w];
    neighbor[w] |= bit[v];
    hasNeighbor |= (bit[v] | bit[w]);
  }

  for (int i = 0; i < n; i++)
    printf("%d %lu\n", i, neighbor[i]);
  printf("%lu\n", hasNeighbor);

  return 0;
}
    
