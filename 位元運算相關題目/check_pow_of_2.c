/**
 * @file check_pow_of_2.c
 * @author your name (you@domain.com)
 * @brief  這題是要求你實作一個函數，這個函數會檢查輸入的數字是否為2的次方數，
 *         由於2的次方數只有一個bit是1，所以如果一個數字是2的次方數的話，他-1就會使該bit變成0
 *         例如8是2的3次方數，8-1=7，7的二進位是0111，8的二進位是1000
 *         兩者做AND運算後會得到0，所以8是2的次方數。
 * @version 0.1
 * @date 2024-09-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int check2pow(int num){
    if(!num)
        return 0;
    int mask = num - 1;
    return !(num & mask);
}

int main(int argc, char **argv){

    printf("Is power of 2? %d\n",check2pow(atoi(argv[1])));
    return 0;
}
