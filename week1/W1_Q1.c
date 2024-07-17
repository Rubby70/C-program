//	99 乘法表

#include <stdio.h>


int main(void){

    int k;
    for(int i = 1; i < 10; i ++){
        printf("%d:\n", i);
        for(int j = 1; j < 10; j ++){
            k = i * j;
            printf("%d * %d = %d\n", i, j, k);
        }
        printf("\n");
    }
    return 0;

}