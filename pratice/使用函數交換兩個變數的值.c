#include <stdio.h>


void exchange(int *, int *);

int main(void){

    int a = 3;
    int b = 5;
    exchange(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;

}

void exchange(int *a, int *b){

    int t = *a;
    *a = *b;
    *b = t;

}