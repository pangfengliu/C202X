#include<stdio.h>
int main()
{
    int k, one, two ,three, four, out;
    scanf("%d", &k);
    if(k = 0){
        for(one = 1; one <=9; one++){
            out = one * 1000 + one * 100 + one * 10 + one;
            printf("%d\n", out);
        }
    }
    else{
    for(one = 1; (one <= 9); one++){
     for(two = 0; (((two >= 0) && (two <= 9) && two <= (one + k )) || (two >= (one - k) && (two >= 0) && (two <= 9))); two++){
        for(three = 0; (((three >= 0) && (three <= 9) && three <= (two + k)) || (three >= (two - k) && three >= 0 && (three <= 9))); three++){
            for(four = 0; (((four >= 0) && (four <= 9) && four <= (three + k)) || (four >= (three - k) && (four >= 0) && (four <= 9))); four++){
                out = one * 1000 + two * 100 + three *10 + four;
                printf("%d\n", out);
            }
 
        }
     }
    }
   }
 
}
