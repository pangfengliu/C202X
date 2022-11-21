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
  int covered;
  char string[MAXSTRINGP1];
} Word;
 
int min(int x, int y)
{
  return(x < y? x : y);
}
 
int select(const Word word[MAXN], const int covered, const int currentCost, 
	   const int wordIndex, const int N)
{
#ifdef DEBUG
  printf("covered %x target %x\n", covered, ((1 << LETTERS) - 1));
#endif
  if (covered == ((1 << LETTERS) - 1))
    return currentCost;
 
  if (wordIndex == N)
    return INT32_MAX;
 
  return min(select(word, covered | word[wordIndex].covered,
		    currentCost + word[wordIndex].cost,
		    wordIndex + 1, N),
	     select(word, covered, currentCost, wordIndex + 1, N));
}

int main()
{
  int N;
  assert(scanf("%d", &N) == 1);
  assert(N <= MAXN);
 
  Word word[MAXN];
  for (int i = 0; i < N; i++) {
    assert(scanf("%s%d", word[i].string, &(word[i].cost)) == 2);
    int len = strlen(word[i].string);
    word[i].covered = 0;
    for (int j = 0; j < len; j++)
      word[i].covered |= (1 << (word[i].string[j] - 'a'));
  }
 
  int covered = 0;
  printf("%d\n", select(word, covered, 0, 0, N));
 
  return 0;
}
