#include <stdio.h>


int count_num(char []);

int main(void){

    char A[] = "Hello world";
    printf("\n%s\n", A);
    printf("%d\n", count_num(A));
    printf("%ld\n", sizeof(A));
    return 0;

}

int count_num(char arr[]){

    int i = 0;
    while(arr[i] != '\0'){
        i ++;
    }
    return i;

}