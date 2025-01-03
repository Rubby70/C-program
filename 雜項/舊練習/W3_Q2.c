// 寫一個程式  我們會輸入任意數字N， N > 0
// 對於所有小於N的正整數  計算所有不是3的倍數的數字的和
// Ex:  輸入N = 10 
// 那你就要印出 1+2+4+5+7+8
#include "stdio.h"


int main(void){

    int N;
    int sum = 1;
    scanf("%d", &N);
    if(N == 1){
        printf("Sum is: 0.\n");
        return 0;
    }
    printf("1");
    for(int i = 2; i < N; i ++){
        if(i % 3 == 0){
            continue;
        }
        sum += i;
        printf("+%d", i);
    }
    printf("\nSum is: %d.\n", sum);
    return 0;
    
}