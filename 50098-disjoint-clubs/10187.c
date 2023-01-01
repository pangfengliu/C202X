#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
 
bool disjoint(uint64_t a, uint64_t b)
{
  return ((a & b) == 0);
}

void printClub(int club[], int num)
{
  for (int i = 0; i < num; i++)
    printf("%d\n", club[i]);
}
 
bool findDisjointSet(int club, int numClub,
             uint64_t clubMember[],
             uint64_t peopleSelected,
             int numClubSelected, int numClubToSelect,
             int clubSelected[])
{
  if (numClubSelected == numClubToSelect) {
    printClub(clubSelected, numClubToSelect);
    return true;
  }
 
  if (club >= numClub)
    return false;
 
  if (disjoint(peopleSelected, clubMember[club])) {     /* select */
    clubSelected[numClubSelected] = club;
    if (findDisjointSet(club + 1, numClub, clubMember,
			peopleSelected | clubMember[club],
			numClubSelected + 1, numClubToSelect, clubSelected))
      return true;
  }
  
  /* not select */
  return findDisjointSet(club + 1, numClub, clubMember, peopleSelected,
			 numClubSelected, numClubToSelect, clubSelected);
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

#ifdef DEBUG
  for (int club = 0; club < numClub; club++)
    printf("%lu\n", clubMember[club]);
#endif

  int clubSelected[numClub];
  findDisjointSet(0, numClub, clubMember, 0, 0, numClubToSelect, clubSelected);
  return 0;
}
