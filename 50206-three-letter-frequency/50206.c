#include <stdio.h>
#include <string.h>
 
#define N 100000
#define L 26
 
int main()
{
  char word[N + 1];
  int frequency[L][L][L] = {{{0}}};
 
  while (scanf("%s", word) != EOF) {
    puts(word);
    int length = strlen(word);
    if (length >= 3) {
      for (int i = 0; i < length - 2; i++)
	frequency[word[i] - 'a'][word[i + 1] - 'a'][word[i + 2] - 'a']++;
    }
  }

  for (int i = 0; i < L; i++)
    for (int j = 0; j < L; j++)
      for (int k = 0; k < L; k++)
	if (frequency[i][j][k] > 0)
	  printf("frequency[%c][%c][%c] = %d\n",
		 'a' + i, 'a' + j, 'a' + k, frequency[i][j][k]);
    
  return 0;
}
