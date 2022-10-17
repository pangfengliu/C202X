#include <stdio.h>
#include <string.h>
 
#define N 100000
#define L 26
 
int main()
{
  char word[N + 1];
 
  while (scanf("%s", word) != EOF) 
    puts(word);

  return 0;
}
