#include "stdio.h"
#include "stdlib.h"


int main(void){

    int **ptr2ptr = (int **)malloc(10 * sizeof(int *));
    for(int i = 0; i < 10; i ++){
        ptr2ptr[i] = (int *)malloc(10 * sizeof(int));
    }

    for(int i = 0; i < 10; i ++){
        for(int j = 0; j < 10; j ++){
            ptr2ptr[i][j] = i * j;
        }
    }

    for(int i = 0; i < 10; i ++){
        for(int j = 0; j < 10; j ++){
            printf("%d * %d = %d\n", i, j, ptr2ptr[i][j]);
        }
        printf("\n");
    }

    return 0;

}