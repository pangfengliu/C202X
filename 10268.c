#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
 
#define MAXN 4
 
typedef struct solution {
  bool toggle[MAXN * MAXN];
  int num;
} Solution;
 
bool correct(Solution *sptr, int light[], int N)
{
  int toggleTimes[MAXN * MAXN] = {0};
  for (int i = 0; i < N * N; i++)
    if (sptr->toggle[i]) {
      toggleTimes[i]++;
      if (i % N > 0)        /* left */
	toggleTimes[i - 1]++;
      if (i % N < N - 1)    /* right */
	toggleTimes[i + 1]++;
      if (i / N > 0)        /* up */
	toggleTimes[i - N]++;
      if (i / N < N - 1)    /* down */
	toggleTimes[i + N]++;
    }
 
  for (int i = 0; i < N * N; i++)
    if ((light[i] + toggleTimes[i]) % 2 != 0)
      return false;
 
  return true;
}
 
void printSolution(Solution *sptr, int N)
{
  for (int i = 0; i < N * N; i++)
    if (sptr->toggle[i])
      printf("%d ", i);
  printf("\n");
}
 
void testToggle(Solution *sptr, Solution *best, int level, int N, int light[])
{
  if (level == N * N) {
    if (correct(sptr, light, N) && sptr->num < best->num)
      *best = *sptr;
    return;
  }
 
  sptr->toggle[level] = true;
  sptr->num++;
  testToggle(sptr, best, level + 1, N, light);
  sptr->toggle[level] = false;
  sptr->num--;
 
  testToggle(sptr, best, level + 1, N, light);
}
 
int main()
{
  Solution solution;
  Solution *sptr = &solution;
 
  int N;
  scanf("%d", &N);
  assert(N <= MAXN);
  int light[MAXN * MAXN] = {0};
  int index;
  while (scanf("%d", &index) != EOF) 
    light[index] = 1;
 
  sptr->num = 0;
  for (int i = 0; i < N * N; i++)
    sptr->toggle[i] = false;
 
  Solution best;
  best.num = N * N + 1;
 
  testToggle(sptr, &best, 0, N, light);
  printSolution(&best, N);
}
