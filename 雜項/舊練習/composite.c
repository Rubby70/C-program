#include <stdio.h>


int main(void){

    int composite[101];
    int n; //總共檢查n個數字
    int i; //用來將數字依序填入數列
    int j; //用來檢查是否為質數
    int isPrime;
    scanf("%d", &n);
    for (i = 0; i < n; i++) //將想被判斷的數依序填入數列
        scanf ("%d", &composite[i]);
    for (i = 0; i < n; i++){
        isPrime = 1; //先假設是質數
        for (j = 2; j < composite[i]; j++){
            if (composite[i] % j == 0){ //若有任意j可以整除
                isPrime = 0; //則判斷不為質數
                break; //結束本次for loop，開始判斷下一個composite[i]
            }
        }
        if (isPrime == 1)
            printf("%d\n", composite[i]);
    }

    return 0;
}