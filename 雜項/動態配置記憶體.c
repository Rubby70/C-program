#include <stdio.h>
#include <stdlib.h>


int main(void){

    int *A = 0;
    int length = 0;

    while(1){
        int input;
        printf("請輸入數字: ");
        scanf("%d", &input);
        if(input <= 0){
            break;
        }
        
        int *larger = (int *)malloc(sizeof(int) * (length + 1));
        for(int i = 0; i <length; i ++){
            larger[i] = A[i];
        }
        free(A);
        A = larger;
        
        //A = realloc(A, sizeof(int) * (length + 1));

        A[length] = input;
        length ++;
    }

    printf("\n輸入過的數字:[ ");
    for(int i = 0; i < length; i ++){
        printf("%d ", A[i]);
    }
    printf("]\n");
    return 0;

}