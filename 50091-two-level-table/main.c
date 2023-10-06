#include <stdio.h>
#include <assert.h>
#include "constructTable.h"
 
int main(){
    int N, M;
    int A[100] = {}, B[500] = {};
    assert(scanf("%d%d", &N, &M) == 2);
    for(int i = 0; i < N; i++)
      assert(scanf("%d", &A[i]) == 1);
    for(int i = 0; i < M; i++)
      assert(scanf("%d", &B[i]) == 1);
 
    int ***ptr;
    ptr = constructTable(A, B);
    for(int i = 0; *(ptr+i) != NULL; i++)
        for(int j = 0; j < A[i]; j++)
            for(int k = 0; *(*(*(ptr+i)+j)+k) != 0; k++)
                printf("%d ", *(*(*(ptr+i)+j)+k));
    return 0;
}
