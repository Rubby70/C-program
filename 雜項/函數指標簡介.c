#include <stdio.h>



void hello();

int main(void){

    printf("\n");

    hello();

    printf("\n");

    void (*func)() = &hello;
    (*func)();
    func();

    printf("\n");
    return 0;

}

void hello(){

    printf("Hello World\n");

}