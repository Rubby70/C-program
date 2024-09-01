#include <stdio.h>


void printbit(int input){
    
    for(int i = 31; i >= 0; i --){
        printf("%d", (input >> i) & 1);
    }
    printf("\t -> %d", input);

}
void printbit2(int input){

    for(int i = 31; i >= 0; i --){
        printf("%d", (input >> i) & 1);
    }
    printf("\t -> %u", input);

}

int main(void){

    // int a = 45;
    // printbit(a);
    // printbit(a >> 1);
    // printbit(a >> 2);

    // printbit(a << 1);

    // printf("\nunsigned int\n");
    // unsigned int u = 4000000000;
    // printbit2(u); 
    // printbit2(u >> 1);

    int n = 45; // 101101
    printbit(n);
    printf(" 初始n\n");
    // 將第5個數字改成1
    int mask = 1 << 4;
    n |= mask; 
    printbit(n);
    printf(" 將第5個數字改成1\n");
    // 將第3個數字改成0
    mask = (1 << 2);
    n ^= mask;
    printbit(n);
    printf(" 將第3個數字改成0\n");
    // 將第4個1改成0
    mask = ~(1 << 3);
    n &= mask;
    printbit(n);
    printf(" 將第4個1改成0\n");
    return 0;

}