#include <stdio.h>


int main(void){

    int A[5] = {0, 1, 2, 3, 4};
    int *B = &A[0];
    int *C = A;

    printf("B: %d\n", *B + 3);
    printf("C: %d\n", *C + 2);
    return 0;

}