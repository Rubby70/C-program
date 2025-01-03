#include <stdio.h>


int main(void){

    int A[5] = {0, 1, 2, 3, 4};
    int *U = &A[0];
    int *K = A;
    int *R = &A[1];
    R = R + 1;

    for(int i = 0; i < 5; i ++){
        printf("%d ", A[i]);
    }
    printf("\nU: ");
    for(int i = 0; i < 5; i ++){
        printf("%d ", *U + i);
    }
    printf("\nK: ");
    for(K = A; K != &A[5]; K ++){
        printf("%d ", *K);
    }
    printf("\n");
    printf("R: %d\n", *R); // A[2];
    return 0;

}