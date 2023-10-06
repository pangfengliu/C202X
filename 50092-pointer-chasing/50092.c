#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
int digits(char *string)
{
  for (int i = 0; i < strlen(string); i++)
    if (!isdigit(string[i]))
      return 0;
  return 1;
}
 
void chasing(int **A[], int a, int *B[], int b, int C[], int c)
{
  for (int i = 0; i < a; i++)
    A[i] = NULL;
  for (int i = 0; i < b; i++)
    B[i] = NULL;
  char line[100];
  while (fgets(line, 100, stdin) != NULL) {
    char *first = strtok(line, " \t\n");
    if (first == NULL) {
      printf("0\n");
      break;
    }
    char *index1ptr = strtok(NULL, " \t\n");
    if (index1ptr == NULL) {
      printf("0\n");
      break;
    }
 
    int index1;
    if (digits(index1ptr))
      index1 = atoi(index1ptr);
    else {
      printf("0\n");
      break;
    }
 
    char *second = strtok(NULL, " \t\n");
    if (second == NULL) {
      printf("0\n");
      break;
    }
 
    char *index2ptr = strtok(NULL, " \t\n");
    if (index2ptr == NULL) {
      printf("0\n");
      break;
    }
 
    int index2;
    if (digits(index2ptr))
      index2 = atoi(index2ptr);
    else {
      printf("0\n");
      break;
    }
 
    if (strtok(NULL, " \t\n") != NULL) {
      printf("0\n");
      break;
    }
 
#ifdef DEBUG
    printf("%s %d %s %d\n", first, index1, second, index2);
#endif
    int correct = 1;
    if (strcmp(first, "A") == 0) {
    if (strcmp(second, "B") != 0 || index1 < 0 || index1 >= a || index2 < 0 || index2 >= b)
    correct = 0;
      else
    A[index1] = &(B[index2]);
      } else if (strcmp(first, "B") == 0) {
    if (strcmp(second, "C") != 0 || index1 < 0 || index1 >= b || index2 < 0 || index2 >= c)
    correct = 0;
      else
    B[index1] = &(C[index2]);
    } else
      correct = 0;
 
    if (correct)
      printf("1\n");
    else
      printf("0\n");
  }
}
