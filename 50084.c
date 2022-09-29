#include <stdio.h>
#include <assert.h>
#include <limits.h>
 
#define MAXJ 500
#define MAXTPERJOB 500

int max(int a, int b)
{
  return (a > b? a : b);
}

int main()
{
  int M, J;
  assert(scanf("%d%d", &M, &J) == 2);
  assert(M == 1);
#ifdef DEBUG
  printf("J %d\n", J);
#endif

  int Jready[MAXJ];
  int numTask[MAXJ];
  int time[MAXJ][MAXTPERJOB];

  int taskTotal = 0;
  for (int j = 0; j < J; j++) {
    assert(scanf("%d%d", &(Jready[j]), &(numTask[j])) == 2);
    assert(Jready[j] == 0);
#ifdef DEBUG
    printf("ready %d num %d\n", Jready[j], numTask[j]);
#endif
    for (int t = 0; t < numTask[j]; t++) {
      int machine;
      assert(scanf("%d%d", &machine, &time[j][t]) == 2);
      assert(machine == 0); /* a single machine */
#ifdef DEBUG
      printf("time for task %d = %d\n", t, time[j][t]);
#endif
    }
    taskTotal += numTask[j];
  }
#ifdef DEBUG
  printf("total task = %d\n", taskTotal);
#endif

  int currentTask[MAXJ] = {0};
  int Mready = 0;
  for (int t = 0; t < taskTotal; t++) {
    int ECtime = INT_MAX;
    int ECjob = -1;
    for (int j = 0; j < J; j++) {
      if (currentTask[j] < numTask[j]) { /* there are still tasks */
	int completion = max(Mready, Jready[j]) + time[j][currentTask[j]];
	if (completion < ECtime) { /* choose the smaller index */
	  ECtime = completion;
	  ECjob = j;
	}
      }
    }
    assert(ECjob != -1);
#ifdef DEBUG
    printf("next task of job %d completes at %d\n", ECjob, ECtime);
#endif
    Jready[ECjob] = ECtime;
    Mready = ECtime;
    currentTask[ECjob]++;
  }
  
  for (int j = 0; j < J; j++)
    printf("%d\n", Jready[j]);
  return 0;
}
