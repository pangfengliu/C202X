#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#define LETTERS 26
#define MAXN 20
#define MAXSTRINGP1 51

typedef struct word {
  int cost;
  char string[MAXSTRINGP1];
} Word;


void incCount(int count[LETTERS], char *string)
{
  int length = strlen(string);
  for (int i = 0; i < length; i++)
    count[string[i] - 'a']++;
}
 
void decCount(int count[LETTERS], char *string)
{
  int length = strlen(string);
  for (int i = 0; i < length; i++)
    count[string[i] - 'a']--;
}
 
bool ok(int count[LETTERS])
{
  for (int i = 0; i < LETTERS; i++)
    if (count[i] == 0)
      return false;
 
  return true;
}
 
int min(int x, int y)
{
  return(x < y? x : y);
}
 
int select(Word word[MAXN], int count[LETTERS], int currentCost, 
	   int wordIndex, int N)
{
  if (ok(count))
    return currentCost;
 
  if (wordIndex == N)
    return INT32_MAX;
 
  incCount(count, word[wordIndex].string);
  int selectCost = 
    select(word, count, currentCost + word[wordIndex].cost,
	   wordIndex + 1, N);
  decCount(count, word[wordIndex].string);
  int notSelectCost = 
    select(word, count, currentCost, wordIndex + 1, N);
 
  return min(selectCost, notSelectCost);
}

int main()
{
  int N;
  assert(scanf("%d", &N) == 1);
  assert(N <= MAXN);
 
  Word word[MAXN];
  for (int i = 0; i < N; i++) 
    assert(scanf("%s%d", word[i].string, &(word[i].cost)) == 2);
 
  int count[LETTERS] = {0};
  printf("%d\n", select(word, count, 0, 0, N));
 
  return 0;
}
