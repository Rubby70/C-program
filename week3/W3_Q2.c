// 輸入任意數字N， N > 0 對於所有小於N的正整數  計算所有不是3的倍數的數字的和

#include <stdio.h>


int find_max_multiple_of_3(int);

int main(void){

    int N;
    printf("\n請輸入N: ");
    scanf("%d", &N);
    if(N <= 0){
        printf("數字不符合規定\n\n");
        return 0;
    }
    int max_multiple_of_3 = find_max_multiple_of_3(N);

    int sum_all = (1 + N) * N / 2;
    int sum_3 = (3 + max_multiple_of_3) * (N / 3) / 2;
    int result = sum_all - sum_3;
    printf("\n1~N的總和: %d\n", sum_all);
    printf("3的倍數的數字的總和: %d\n", sum_3);
    printf("** 不是3的倍數的數字的總和: %d **\n\n", result);
    return 0;

}

int find_max_multiple_of_3(int N){

    int max_multiple_of_3;
    switch(N % 3){ //對N求3的餘數來找最大的3的倍數
        case 0: 
            max_multiple_of_3 = N; // if N = 3 , 最大的3的倍數是3
            break;
        case 1:
            max_multiple_of_3 = N - 1; // if N = 4 , 最大的3的倍數是3 (4 - 1)
            break;
        case 2:
            max_multiple_of_3 = N - 2; // if N = 5 , 最大的3的倍數是3 (5 - 2)
            break;
    }
    return max_multiple_of_3;

}