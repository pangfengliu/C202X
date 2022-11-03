#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 105
#define MAXS (MAXN * MAXN)
#define MAXC 10
#define MAXSTRLENP1 6		/* with '\0' */

#define NDEBUG

int max(int a, int b)
{
  return (a > b? a : b);
}

typedef struct {
  int N;
  char string[MAXN][MAXN][MAXN][MAXSTRLENP1];
  int height[MAXN][MAXN];
} Tower;
	
void getTower(Tower *tower)
{
  int N;
  assert(scanf("%d", &N) == 1);

  tower->N = N;
  for (int layer = 1; layer <= N; layer++)
    for (int row = 0; row < layer; row++)
      for (int col = 0; col < layer; col++)
	assert(scanf("%s", tower->string[row][col][N - layer]) == 1);
  for (int row = 0; row < N; row++)
    for (int col = 0; col < N; col++)
      tower->height[row][col] = N - max(row, col);
}

int f(char s[], int K)
{
  int len = strlen(s);
  int v = 0;
  for (int i = 0; i < len; i++)
    v = v * 29 + (s[i] - 'a' + 1);
  return (v % K);
}

/* find key in the hash table, if found remove it and return its tower
   index, if not return -1 */

int findRemove(char hashTableString[MAXS][MAXC][MAXSTRLENP1],
	       int hashTableTindex[MAXS][MAXC],
	       char key[], int hash)
{
  for (int i = 0; i < MAXC; i++)
    if ((hashTableString[hash][i][0] != '\0') &&
	strcmp(hashTableString[hash][i], key) == 0) {
      hashTableString[hash][i][0] = '\0'; /* remove the key */
      return (hashTableTindex[hash][i]);
    }
  return -1;			/* no match */
}

/* insert a key into the hash table */

void insert(char hashTableString[MAXS][MAXC][MAXSTRLENP1],
	    int hashTableTindex[MAXS][MAXC],
	    char key[], int tindex, int hash)
{
  for (int i = 0; i < MAXC; i++)
    if (hashTableString[hash][i][0] == '\0') { /* empty */
      strcpy(hashTableString[hash][i], key);
      hashTableTindex[hash][i] = tindex;
      return;
    }
  printf("no space found");
  exit(-1);
}

void printHashTable(char hashTableString[MAXS][MAXC][MAXSTRLENP1],
		    int hashTableTindex[MAXS][MAXC])
{
  for (int s = 0; s < MAXS; s++) {
    for (int c = 0; c < MAXC; c++)
      if (hashTableString[s][c][0] != '\0')
	printf("(%s %d)", hashTableString[s][c], hashTableTindex[s][c]);
    printf("\n");
  }
}

char *getKey(Tower *tower, int row, int col)
{
  assert(tower->height[row][col] > 0);
  return (tower->string[row][col][tower->height[row][col] - 1]);  
}

void pairing(int pair[], int matchIndex[], int row[], int col[], int S,
	     const int mtindex[], Tower *tower,
	     char hashTableString[MAXS][MAXC][MAXSTRLENP1],
	     int hashTableTindex[MAXS][MAXC], int K)
{
  for (int i = 0; i < 2; i++) {
    pair[i] = 0;
    matchIndex[i] = -1;
    if (tower->height[row[i]][col[i]] > 0) {
      char *key = getKey(tower, row[i], col[i]);
      int hash = f(key, K);
      matchIndex[i] = findRemove(hashTableString, hashTableTindex, key, hash);
      if (matchIndex[i] == -1) /* no match */
	insert(hashTableString, hashTableTindex, key, mtindex[i], hash);
      else
	pair[i] = 1;
    }
  }
}

int main()
{
  Tower tower;
  getTower(&tower);
  int S = tower.N * tower.N;		/* hash table size */
  
  char hashTableString[MAXS][MAXC][MAXSTRLENP1];
  for (int i = 0; i < S; i++)
    for (int j = 0; j < MAXC; j++)
      hashTableString[i][j][0] = '\0';

  int hashTableTindex[MAXS][MAXC];
  int tindex = 0;
  int paired = 0;
  int mtindex[2];
  for (int row = 0; row < tower.N; row++)
    for (int col = 0; col < tower.N; col++, tindex++) {
      char *key = getKey(&tower, row, col);
#ifdef DEBUG
      printf("insert %s into hashTable\n", key);
#endif
      int hash = f(key, tower.N * tower.N);
      int matchIndex = findRemove(hashTableString, hashTableTindex, key, hash);
      if (matchIndex == -1)	/* not found */
	insert(hashTableString, hashTableTindex, key, tindex, hash);
      else {
	paired++;
	mtindex[0] = matchIndex;
	mtindex[1] = tindex;
      }
    }
  assert(paired <= 1);
#ifdef DEBUG  
  printHashTable(hashTableString, hashTableTindex);
#endif
	
  /* there will be a pair to remove at mtindex1 and mtindex2 */
  while (paired > 0) {

#ifdef DEBUG
    printf("\nmtindex1 %d mtindex2 %d paired %d\n", mtindex[0], mtindex[0], paired);
#endif

    paired = 0;
    int row[2] = {mtindex[0] / tower.N, mtindex[1] / tower.N};
    int col[2] = {mtindex[0] % tower.N, mtindex[1] % tower.N};
    char *key1 = getKey(&tower, row[0], col[0]);
    char *key2 = getKey(&tower, row[1], col[1]);
    assert(strcmp(key1, key2) == 0);
    printf("%s\n", key1);
    tower.height[row[0]][col[0]]--;	/* remove numbers from tower */
    tower.height[row[1]][col[1]]--;

    if (tower.height[row[0]][col[0]] > 0 && tower.height[row[1]][col[1]] > 0 &&
	getKey(&tower, row[0], col[0]) == getKey(&tower, row[1], col[1])) {
      paired = 1;
      continue;
    }

    int pair[2], matchIndex[2];
    pairing(pair, matchIndex, row, col, S, mtindex, &tower, 
	    hashTableString, hashTableTindex, tower.N * tower.N);
    paired = pair[0] + pair[1];
    assert(paired <= 1);
    if (paired > 0) {
      if (pair[0] == 1) 
	mtindex[1] = matchIndex[0];
      else {
	assert(pair[1] == 1);
	mtindex[0] = matchIndex[1];
      }
    }
  }
  return 0;
}
