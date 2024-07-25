#include <stdio.h>


int main(void){

    printf("Hellow World 1\n"); // printf => &printf
    (&printf)("Hellow World 2\n");
    (*printf)("Hellow World 3\n"); // *printf => &(&printf) => printf => &printf
    return 0;

}