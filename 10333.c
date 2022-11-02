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

void getTower(int N, char tower[MAXN][MAXN][MAXN][MAXSTRLENP1])
{
  for (int layer = 1; layer <= N; layer++)
    for (int row = 0; row < layer; row++)
      for (int col = 0; col < layer; col++)
	assert(scanf("%s", tower[row][col][N - layer]) == 1);
}

void computeHeight(int N, int height[MAXN][MAXN])
{
  for (int row = 0; row < N; row++)
    for (int col = 0; col < N; col++) {
      height[row][col] = N - max(row, col);
#ifdef DEBUG
      printf("height [%d][%d] = %d\n", row, col, height[row][col]);
#endif
    }
}

int f(char s[], int K)
{
  int len = strlen(s);
  int v = 0;
  for (int i = 0; i < len; i++)
    v += v * 29 + (s[i] - 'a' + 1);
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

char *getKey(char tower[MAXN][MAXN][MAXN][MAXSTRLENP1], int row, int col,
	   int height[MAXN][MAXN])
{
#ifdef DEBUG
  printf("getKey %d %d\n", row, col);
#endif
  assert(height[row][col] > 0);
  return tower[row][col][height[row][col] - 1];  
}

void pairing(int pair[], int matchIndex[], int row[], int col[], int S,
	     const int mtindex[], char tower[MAXN][MAXN][MAXN][MAXSTRLENP1],
	     int height[MAXN][MAXN],
	     char hashTableString[MAXS][MAXC][MAXSTRLENP1],
	     int hashTableTindex[MAXS][MAXC], int K)
{
  for (int i = 0; i < 2; i++) {
    pair[i] = 0;
    matchIndex[i] = -1;
    if (height[row[i]][col[i]] > 0) {
      char *key = getKey(tower, row[i], col[i], height);
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
  int N;
  assert(scanf("%d", &N) == 1);
  int S = N * N;		/* hash table size */

  char tower[MAXN][MAXN][MAXN][MAXSTRLENP1];
  getTower(N, tower);
  
  int height[MAXN][MAXN];
  computeHeight(N, height);
  
  char hashTableString[MAXS][MAXC][MAXSTRLENP1];
  for (int i = 0; i < S; i++)
    for (int j = 0; j < MAXC; j++)
      hashTableString[i][j][0] = '\0';

  int hashTableTindex[MAXS][MAXC];
  int tindex = 0;
  int paired = 0;
  int mtindex[2];
  for (int row = 0; row < N; row++)
    for (int col = 0; col < N; col++, tindex++) {
      char *key = getKey(tower, row, col, height);
#ifdef DEBUG
      printf("insert %s into hashTable\n", key);
#endif
      int hash = f(key, N * N);
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
    int row[2] = {mtindex[0] / N, mtindex[1] / N};
    int col[2] = {mtindex[0] % N, mtindex[1] % N};
    char *key1 = getKey(tower, row[0], col[0], height);
    char *key2 = getKey(tower, row[1], col[1], height);
    assert(strcmp(key1, key2) == 0);
    printf("%s\n", key1);
    height[row[0]][col[0]]--;	/* remove numbers from tower */
    height[row[1]][col[1]]--;

    if (height[row[0]][col[0]] > 0 && height[row[1]][col[1]] > 0 &&
	getKey(tower, row[0], col[0], height) ==
	getKey(tower, row[1], col[1], height)) {
      paired = 1;
      continue;
    }

    int pair[2], matchIndex[2];
    pairing(pair, matchIndex, row, col, S, mtindex, tower, height,
	    hashTableString, hashTableTindex, N * N);
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
