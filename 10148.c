#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

void incCount(int count[], char *string)
{
  int length = strlen(string);
  for (int i = 0; i < length; i++)
    count[string[i] - 'a']++;
}
 
void decCount(int count[], char *string)
{
  int length = strlen(string);
  for (int i = 0; i < length; i++)
    count[string[i] - 'a']--;
}
 
bool ok(int count[26])
{
  for (int i = 0; i < 26; i++)
    if (count[i] == 0)
      return false;
 
  return true;
}
 
int min(int x, int y)
{
  return(x < y? x : y);
}
 
int select(char word[][51], int cost[], int count[], int currentCost, 
	   int wordIndex, int N)
{
  if (ok(count))
    return currentCost;
 
  if (wordIndex == N)
    return INT32_MAX;
 
  incCount(count, word[wordIndex]);
  int selectCost = 
    select(word, cost, count, currentCost + cost[wordIndex], wordIndex + 1, N);
  decCount(count, word[wordIndex]);
  int notSelectCost = 
    select(word, cost, count, currentCost, wordIndex + 1, N);
 
  return min(selectCost, notSelectCost);
}
 
int main()
{
  int N;
  assert(scanf("%d", &N) == 1);
 
  char word[20][51];
  int cost[20];
  for (int i = 0; i < N; i++) 
    assert(scanf("%s%d", word[i], &(cost[i])) == 2);
 
  int count[26] = {0};
  printf("%d\n", select(word, cost, count, 0, 0, N));
 
  return 0;
}
