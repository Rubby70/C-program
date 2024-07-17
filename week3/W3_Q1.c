// 寫一個程式 他可以計算使用者輸入的數字的總和，我會不停的輸入一個數字 
// 在輸入後你要自己先計算好總和 但不印出。  
// 直到我輸入了一個負數  就把總和印出 並把程式結束。

#include <stdio.h>


int main(void){

    int input;
    int sum = 0;
    while(1){
        printf("請輸入數字: ");
        scanf("%d", &input);
        if(input < 0){
            break;
        }
        sum += input;
    }
    printf("總和: %d\n", sum);
    return 0;

}