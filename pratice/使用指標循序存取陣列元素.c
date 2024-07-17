#include <stdio.h>


int main(void){

    int A[5] = {0, 1, 2, 3, 4};
    int *B = A;
    // for(int i = 0; i < 5; i ++){
    //     printf("%d ", *B + i);
    // }
    while(B != &A[5]){
        printf("%d ", *B);
        B ++;
    }
    printf("\n");
    return 0;

}