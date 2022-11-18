#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
 
bool disjoint(uint64_t a, uint64_t b)
{
  return ((a & b) == 0);
}

#define MAXNUMCLUB 101
#define MAXBIT 64

int main()
{
  int numClub;
  assert(scanf("%d", &numClub) == 1);
  assert(numClub < MAXNUMCLUB);
  int numClubToSelect;
  assert(scanf("%d", &numClubToSelect) == 1);
  assert(numClubToSelect > 1 && numClubToSelect <= numClub);
 
  uint64_t clubMember[numClub];
  for (int club = 0; club < numClub; club++) {
    clubMember[club] = 0;
    int numMember;
    assert(scanf("%d", &numMember) == 1);
    int index;
    for (int m = 0; m < numMember; m++) {
      assert(scanf("%d", &index) == 1);
      assert(index >= 0 && index <= MAXBIT);
      clubMember[club] |= (((uint64_t)1) << index);
    }
  }

  for (int club = 0; club < numClub; club++) 
    printf("%lu\n", clubMember[club]);

}
