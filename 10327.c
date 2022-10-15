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
  int mtindex1, mtindex2, mkey;
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
	mtindex1 = matchIndex;
	mtindex2 = tindex;
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

    int row1 = mtindex1 / N;
    int col1 = mtindex1 % N;
    int row2 = mtindex2 / N;
    int col2 = mtindex2 % N;
    int key1 = getKey(tower, row1, col1, height);
    int key2 = getKey(tower, row2, col2, height);
    assert(key1 == key2);
    printf("%d ", key1);
    height[row1][col1]--;	/* remove numbers from tower */
    height[row2][col2]--;

    if (height[row1][col1] > 0 && height[row2][col2] > 0 &&
	getKey(tower, row1, col1, height) == getKey(tower, row2, col2, height)) {
      paired = 1;
      continue;
    }
    
    int pair1 = 0;
    int matchIndex1 = -1;
    if (height[row1][col1] > 0) {
      key1 = getKey(tower, row1, col1, height);
      matchIndex1 = findRemove(hashTable, key1, S);
      if (matchIndex1 == -1) /* no match */
	insert(hashTable, key1, S, mtindex1);
      else
	pair1 = 1;
    }

    int pair2 = 0;
    int matchIndex2 = -1;
    if (height[row2][col2] > 0) {
      key2 = getKey(tower, row2, col2, height);
      matchIndex2 = findRemove(hashTable, key2, S);
      if (matchIndex2 == -1) /* no match */
	insert(hashTable, key2, S, mtindex2);
      else 
	pair2 = 1;
    }

    paired = pair1 + pair2;
    assert(paired <= 1);
    if (paired > 0) {
      if (pair1 == 1) 
	mtindex2 = matchIndex1;
      else {
	assert(pair2 == 1);
	mtindex1 = matchIndex2;
      }
    }
  }
  printf("\n");
  
  return 0;
}
