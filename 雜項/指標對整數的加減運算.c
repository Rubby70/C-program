#include <stdio.h>


int main(void){

    int A[5] = {0, 1, 2, 3, 4};

    int *B = &A[0];

    printf("%d\n", *B + 1);
    printf("%ld\n", &A[3] - &A[0]);
    return 0;

}