#include <stdio.h>


void print1(int **p, int heigh, int width){

    printf("----------\n");
    for(int i = 0; i < heigh; i ++){
        for(int j = 0; j < width; j ++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    printf("----------\n");

}

void print2(int *p, int heigh, int width){

    printf("----------\n");
    for(int i = 0; i < heigh; i ++){
        for(int j = 0; j < width; j ++){
            printf("%d ", *(p + (i * width) + j));
        }
        printf("\n");
    }
    printf("----------\n");

}

int main(void){

    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int *p[2] = {A[0], A[1]};
    print1(p, 2, 3);

    int B[2][3] = {{1, 2, 3}, {4, 5, 6}};
    print2((int *)B, 2, 3); // == print2((&B[0][0]), 2, 3)

    return 0;

}