#include <stdio.h>


int addone(int *N){

    *N = *N + 1;
    return *N;
    
}

int main(void){

    int A = 5;
    addone(&A);
    printf("%d\n", A);
    return 0;

}