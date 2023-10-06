int findLoop(int N, int *A, int index, int *B[], int *max, int *min, int visited[])
{
  int start =  *max = *min = A[index];
  int i = index;
  visited[index] = 1;
  int length = 1;
  while (*B[i] != start) {
    i = B[i] - A;
    visited[i] = 1;
    if (A[i] > *max)
      *max = A[i];
    if (A[i] < *min)
      *min = A[i];
    length++;
  }
  return length;
}
 
void loops(int N, int *A, int *B[], int ans[4])
{
  int visited[N];
  for (int i = 0; i < N; i++)
    visited[i] = 0;
  int max, min;
  int maxLength = 0;
  int minLength = N + 1;
  int maxMax, minMin;
  for (int i = 0; i < N; i++)
    if (visited[i] == 0) {
      int length = findLoop(N, A, i,  B, &max, &min, visited);
      if (length > maxLength) {
	maxLength = length;
	maxMax = max;
      } else if (length == maxLength && max > maxMax)
	maxMax = max;
 
      if (length < minLength) {
	minLength = length;
	minMin = min;
      } else if (length == minLength && min < minMin)
	minMin = min;
    }
  ans[0] = maxLength;
  ans[1] = minLength;
  ans[2] = maxMax;
  ans[3] = minMin;
}
