#include <stdio.h>
 
int findSupport(int seesaw[], int start, int end)
{
  if (end - start < 2)
    return -1;
 
  for (int support = start; support <= end; support++) {
    /* check if balanced */
    long long int leftTorque = 0;
    for (int left = start; left < support; left++)
      leftTorque += seesaw[left] * (support - left);
    long long int rightTorque = 0;
    for (int right = support + 1; right <= end; right++)
      rightTorque += seesaw[right] * (right - support);
    if (leftTorque == rightTorque)
      return support;
  }
  return -1;
}
 
void findAllSupport(int seesaw[], int start, int end)
{
  int support = findSupport(seesaw, start, end);
  if (support == -1)
    return;
 
  findAllSupport(seesaw, start, support - 1);
  printf("%d\n", support);
  findAllSupport(seesaw, support + 1, end);
}
 
int main()
{
  int seesaw[17000];
  int length; scanf("%d", &length);
  for (int i = 0; i < length; i++) {
    scanf("%d", &(seesaw[i]));
#ifdef DEBUG
    printf("%d\n", seesaw[i]);
#endif
  }
  findAllSupport(seesaw, 0, length - 1);
}
