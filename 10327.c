#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 105
#define MAXS (MAXN * MAXN)
#define MAXC 10

#define KEY 0
#define TINDEX 1

int max(int a, int b)
{
  return (a > b? a : b);
}

void getTower(int N, int tower[MAXN][MAXN][MAXN])
{
  for (int layer = 1; layer <= N; layer++)
    for (int row = 0; row < layer; row++)
      for (int col = 0; col < layer; col++)
	assert(scanf("%d", &(tower[row][col][N - layer])) == 1);
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

int f(int key, int S)
{
  return ((77 * key + 2222) % S);
}

/* find key in the hash table, if found remove it and return its tower
   index, if not return -1 */

int findRemove(int hashTable[MAXS][MAXC][2], int key, int S)
{
  int hash = f(key, S);
  for (int i = 0; i < MAXC; i++)
    if (hashTable[hash][i][KEY] == key) {
      hashTable[hash][i][KEY] = 0; /* remove the key */
      return (hashTable[hash][i][TINDEX]);
    }
  return -1;			/* no match */
}

/* insert a key into the hash table */

void insert(int hashTable[MAXS][MAXC][2], int key, int S, int tindex)
{
  int hash = f(key, S);
  for (int i = 0; i < MAXC; i++)
    if (hashTable[hash][i][KEY] == 0) {
      hashTable[hash][i][KEY] = key;
      hashTable[hash][i][TINDEX] = tindex;
      return;
    }
  printf("no space found");
  exit(-1);
}

void printHashTable(int hashTable[MAXS][MAXC][2], int S, int C)
{
  for (int s = 0; s < S; s++) {
    for (int c = 0; c < C; c++)
      if (hashTable[s][c][KEY] > 0)
	printf("(%d %d)", hashTable[s][c][KEY], hashTable[s][c][TINDEX]);
    printf("\n");
  }
}

int getKey(int tower[MAXN][MAXN][MAXN], int row, int col,
	   int height[MAXN][MAXN])
{
#ifdef DEBUG
  printf("getKey %d %d\n", row, col);
#endif
  assert(height[row][col] > 0);
  return tower[row][col][height[row][col] - 1];  
}

void pairing(int pair[], int matchIndex[], int row[], int col[], int S,
	     const int mtindex[], int tower[MAXN][MAXN][MAXN],
	     int height[MAXN][MAXN], int hashTable[MAXS][MAXC][2])
{
  for (int i = 0; i < 2; i++) {
    pair[i] = 0;
    matchIndex[i] = -1;
    if (height[row[i]][col[i]] > 0) {
      int key = getKey(tower, row[i], col[i], height);
      matchIndex[i] = findRemove(hashTable, key, S);
      if (matchIndex[i] == -1) /* no match */
	insert(hashTable, key, S, mtindex[i]);
      else
	pair[i] = 1;
    }
  }
}

int main()
{
  int N, S, C;
  assert(scanf("%d%d%d", &N, &S, &C) == 3);
  assert(1 <= N && N <= MAXN);
  assert(1 <= S && S <= N * N);
  assert(1 <= C && C <= MAXC);

  int tower[MAXN][MAXN][MAXN];
  getTower(N, tower);
  
  int height[MAXN][MAXN];
  computeHeight(N, height);
  
  int hashTable[MAXS][MAXC][2] = {{{0}}};
  int tindex = 0;
  int paired = 0;
  int mtindex[2];
  for (int row = 0; row < N; row++)
    for (int col = 0; col < N; col++, tindex++) {
      int key = getKey(tower, row, col, height);
#ifdef DEBUG
      printf("insert %d into hashTable\n", key);
#endif
      int matchIndex = findRemove(hashTable, key, S);
      if (matchIndex == -1)	/* not found */
	insert(hashTable, key, S, tindex);
      else {
	paired++;
	mtindex[0] = matchIndex;
	mtindex[1] = tindex;
      }
    }
  assert(paired <= 1);
#ifdef DEBUG  
  printHashTable(hashTable, S, C);
#endif
	
  /* there will be a pair to remove at mtindex1 and mtindex2 */
  while (paired > 0) {

#ifdef DEBUG
    printf("\nmtindex1 %d mtindex2 %d paired %d\n", mtindex1, mtindex2, paired);
#endif

    paired = 0;
    int row[2] = {mtindex[0] / N, mtindex[1] / N};
    int col[2] = {mtindex[0] % N, mtindex[1] % N};
    int key1 = getKey(tower, row[0], col[0], height);
    int key2 = getKey(tower, row[1], col[1], height);
    assert(key1 == key2);
    printf("%d ", key1);
    height[row[0]][col[0]]--;	/* remove numbers from tower */
    height[row[1]][col[1]]--;

    if (height[row[0]][col[0]] > 0 && height[row[1]][col[1]] > 0 &&
	getKey(tower, row[0], col[0], height) ==
	getKey(tower, row[1], col[1], height)) {
      paired = 1;
      continue;
    }

    int pair[2], matchIndex[2];
    pairing(pair, matchIndex, row, col, S, mtindex, tower, height, hashTable);
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
  printf("\n");
  
  return 0;
}
