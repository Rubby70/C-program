#include <stdio.h>
#include <stdlib.h>


int main(void){

    int **ptr2ptr = (int **)malloc(sizeof(int *) * 9);
    for(int i = 0; i < 9; i ++){
        ptr2ptr[i] = (int *)malloc(sizeof(int) * 9);
    }

    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j ++){
            ptr2ptr[i][j] = (i + 1) * (j + 1);
        }
    }

    printf("\n");
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j ++){
            printf("(%d * %d) = %d\n", i + 1, j + 1, ptr2ptr[i][j]);
        }
        printf("\n");
    }
    return 0;

}

