#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#define BITS 64

typedef struct {
  int num;
  uint64_t selected;
} Selection;

void printSelection(const Selection selection, const int n)
{
  for (int i = 0; i < n; i++)
    if (selection.selected & ((uint64_t)(1) << i))
      printf("%d\n", i);
}

bool coverAll(const Selection selection, const uint64_t neighbor[], const int n)
{
  for (int i = 0; i < n; i++) {
    if (selection.selected & ((uint64_t)(1) << i))
      continue;
    if (neighbor[i] & ~(selection.selected))
      return false;
  }
  return true;
}

Selection freindCover(const uint64_t neighbor[], const int i, const int n,
		     const uint64_t hasNeighbor,
		     const Selection selection)
{
  if (coverAll(selection, neighbor, n)) 
    return selection;
  
  Selection noSolution = {INT_MAX, 0};
  if (i >= n)
    return noSolution;
  
  if ((hasNeighbor & ((uint64_t)1 << i)) == 0)
    return freindCover(neighbor, i + 1, n, hasNeighbor,
		       selection);

  Selection add = {selection.num + 1,
		   selection.selected | ((uint64_t)1 << i)};
  Selection yes = freindCover(neighbor, i + 1, n, hasNeighbor, add);
  Selection no = freindCover(neighbor, i + 1, n, hasNeighbor, selection);

  return (no.num < yes.num? no : yes);
}


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

  Selection selected = {0, 0};
  Selection minCover = freindCover(neighbor, 0, n, hasNeighbor, selected);

  printSelection(minCover, n);
  
  return 0;
}
    
