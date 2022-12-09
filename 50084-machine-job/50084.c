#include <stdio.h>
#include <assert.h>
#include <limits.h>
 
#define MAXJ 500
#define MAXM 500
#define MAXTPERJOB 500

int max(int a, int b)
{
  return (a > b? a : b);
}

int main()
{
  int M, J;
  assert(scanf("%d%d", &M, &J) == 2);
#ifdef DEBUG
  printf("M %d J %d\n", M, J);
#endif

  int Jready[MAXJ];		/* job ready time */
  int numTask[MAXJ];

  int taskTotal = 0;
  int machine[MAXJ][MAXTPERJOB];
  int time[MAXJ][MAXTPERJOB];
  for (int j = 0; j < J; j++) {
    assert(scanf("%d%d", &(Jready[j]), &(numTask[j])) == 2);
#ifdef DEBUG
    printf("ready %d num %d\n", Jready[j], numTask[j]);
#endif
    for (int t = 0; t < numTask[j]; t++) {
      assert(scanf("%d%d", &machine[j][t], &time[j][t]) == 2);
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
  int Mready[MAXM] = {0};
  for (int t = 0; t < taskTotal; t++) {
    int ECtime = INT_MAX;
    int ECjob = -1;
    int ECmachine;
    for (int j = 0; j < J; j++) {
      if (currentTask[j] < numTask[j]) { /* there are still tasks */
	int task = currentTask[j];
	int completion =
	  max(Mready[machine[j][task]], Jready[j]) +
	  time[j][task];
	if (completion < ECtime) { /* choose the smaller index */
	  ECtime = completion;
	  ECjob = j;
	  ECmachine = machine[j][task];
	}
      }
    }
    assert(ECjob != -1);
#ifdef DEBUG
    printf("next task of job %d completes at %d\n", ECjob, ECtime);
#endif
    Jready[ECjob] = ECtime;
    Mready[ECmachine] = ECtime;
    currentTask[ECjob]++;
  }
  
  for (int j = 0; j < J; j++)
    printf("%d\n", Jready[j]);
  return 0;
}
