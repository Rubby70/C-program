#include <stdio.h>


int main(void){

    int A[3] = {0, 1, 2};
    int *B[3] = {&A[0], &A[1], &A[2]};
    int (*C)[3] = &A;
    
    printf("\n");
    for(int i = 0; i < 3; i ++){
        printf("%d ", *B[i]);
    }
    printf("\n");
    for(int i = 0; i < 3; i ++){
        printf("%d ", (*C)[i]);
    }
    printf("\n");
    return 0;

}