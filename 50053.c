#include <stdio.h>
#include <string.h>
#include <assert.h>
 
#define MAXLEN 51
#define M 100
 
int search(char *target, char table[][MAXLEN], int N)
{
  for (int i = 0; i < N; i++)
    if (strcmp(target, table[i]) == 0)
      return i;
 
  return -1;			/* not found */
}
 
int main()
{
  int numBooks;
  assert(scanf("%d", &numBooks) == 1);
 
  char author[M][MAXLEN];
  char book[M][MAXLEN];
 
  char authorName[M][MAXLEN];	/* author's name */
  int numAuthors = 0;
 
  for (int i = 0; i < numBooks; i++) {
    assert(scanf("%s%s", author[i], book[i]));
    if (search(author[i], authorName, numAuthors) == -1) {
      strcpy(authorName[numAuthors], author[i]);
      numAuthors++;
    }
  }
  printf("numAuthors %d\n", numAuthors);

  int sold[M] = {0};
  for (int i = 0; i < numBooks; i++) {
    char title[MAXLEN];
    int copy;
    assert(scanf("%s%d", title, &copy) == 2);
    sold[search(author[search(title, book, numBooks)], authorName, numAuthors)] 
      += copy;
  }


  return 0;
}
