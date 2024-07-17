#include <stdio.h>


int main(void){

    int A[5] = {0, 1, 2, 3, 4};
    int *B = A;
    printf("A: ");
    for(int i = 0; i < 5; i ++){
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("B: ");
    for(int i = 0; i < 5; i ++){
        printf("%d ", B[i]);
    }
    printf("\n");
    return 0;

}