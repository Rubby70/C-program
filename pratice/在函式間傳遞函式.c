#include <stdio.h>


int calculation(int (*)(int, int));
int add(int, int);
int multiply(int, int);

int main(void){

    printf("add = %d\n", calculation(add));
    printf("multiply = %d\n", calculation(multiply));
    return 0;

}

int calculation(int (*op)(int a, int b)){

    int result = 1;
    for(int i = 2; i <= 5; i ++){
        result = op(result, i);
    }
    return result;

}

int add(int a, int b){

    return a + b;

}

int multiply(int a, int b){

    return a * b;

}


