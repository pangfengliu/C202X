#include <stdio.h>
 
int inc(int i, int N)
{
  return((i + 1) % N);
}
 
int dec(int i, int N)
{
  return((N + i - 1) % N);
}
 
int right(int col, int N)
{
  return(inc(col, N));
}
 
int up(int row, int N)
{
  return(dec(row, N));
}
 
int down(int row, int N)
{
  return(inc(row, N));
}
 
#define MSIZE 1000
 
int empty(int row, int col, int matrix[MSIZE][MSIZE])
{
  return(matrix[row][col] == 0);
}
 
int main()
{
  int N, k, row, col;
  scanf("%d%d%d%d", &N, &k, &row, &col);

  int matrix[MSIZE][MSIZE] = {0};
  for (int number = 1; number <= N * N; number++) {
    matrix[row][col] = number;
    int newCol = right(col, N);
    int newRow = up(row, N);
    if (empty(newRow, newCol, matrix)) {
      row = newRow;
      col = newCol;
    } else {
      row = down(row, N);
    }
  }
 
  for (int row = 0; row < N; row++)
    for (int col = 0; col < N; col++)
      printf("%d%c", matrix[row][col], (col == N - 1)? '\n' : ' '); 
  return 0;
}
