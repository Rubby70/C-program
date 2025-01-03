#include <stdio.h>


void sort(int *, int *);
void swap(int *, int *);

int main(void){

    int a = 5;
    int b = 3;
    sort(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;

}

void sort(int *a, int *b){
    
    if(*a > *b){
        swap(a, b);
        //swap(&*a, &*b);
    }

}

void swap(int *a, int *b){

    int t = *a;
    *a = *b;
    *b = t;

}