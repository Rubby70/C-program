#include <stdio.h>


int main(void){

    int A[5];
    int *B = &A[0];

    for(int i = 0; i < 5; i++){
        A[i] = 0;
    }

    for(int i = 0; i < 5; i ++){
        *B = 0;
    }

    while(B != &A[5]){
        *B = 0;
        B ++;
    }

    while(B != A + 5){
        *B ++ = 0;
        //*(B ++) = 0;
    }
    
    for(int i = 0; i < 5; i ++){
        printf("%d", A[i]);
    }
    printf("\n");
    return 0;

}