#include <stdio.h>
#include <stdbool.h>


void print2bit(int n){

    for(int i = 31; i >= 0; i --){
        printf("%d", (n >> i) & 1);
    }
    printf("\t -> %d\n", n);

}
void Q1(int n){

    print2bit(n);
    n &= (n - 1);
    print2bit(n);

}
void Q2(int n){

    print2bit(n);
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n = n + 1;
    print2bit(n >> 1);

}
void Q3(int n){

    print2bit(n);
    n &= (- n);
    print2bit(n);

}
void Q4(){

    int length = 4;
    int arr[4] = {1, 2, 5, 4};
    int check = 0;
    for(int i = 0; i <= 4; i ++){
        check ^= (i + 1);
    }
    for(int i = 0; i < 4; i ++){
        check ^= arr[i];
    }
    printf("缺少的數字: %d\n", check);

}
void Q5(int n){

    n &= (n - 1);
    if(n == 0){
        printf("是2的次方\n");
    }
    else{
        printf("不是2的次方\n");
    }

}
void Q6(int n){

    print2bit(n);
    //setbit
    int mask1 = 1 << 1;
    n |= mask1;
    print2bit(n);

    //clearbit
    int mask2 = 1 << 2;
    n &= ~mask2;
    print2bit(n);

    //togglebit
    int mask3 = 1 << 3;
    n ^= mask3;
    print2bit(n);

    //checkbit
    int mask4 = 1 << 4;
    n &= mask4;
    print2bit(n);

}
void Q7(int n){

    //flooring
    int n1 = n;
    print2bit(n1);
    n1 |= n >> 1;
    n1 |= n >> 2;
    n1 |= n >> 4;
    n1 |= n >> 8;
    n1 |= n >> 16;
    n1 = n1 - (n1 >> 1);
    print2bit(n1);

    printf("\n");
    //ceiling
    int n2 = n;
    print2bit(n2);
    n2 |= n2 >> 1;
    n2 |= n2 >> 2;
    n2 |= n2 >> 4;
    n2 |= n2 >> 8;
    n2 |= n2 >> 16;
    n2 += 1;
    print2bit(n2);

}

int main(void){

    int n;
    scanf("%d", &n);
    // Q1(n);
    // Q2(n);
    // Q3(n);
    // Q4();
    // Q5(n);
    // Q6(n);
    Q7(n);
    return 0;

}