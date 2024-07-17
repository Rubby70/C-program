// 輸入10個整數後
// 接著輸入要查詢的數字
// 最後顯示出在輸入的10個整數中
// 最接近的那一個數字是多少
// 若有兩個以上的結果時則顯示較小的數字
// 輸入0則結束

#include <stdio.h>


int main(void){

    int length = 10;
    int input[length];
    printf("\n建立資料庫，請輸入10個數字: ");
    for(int i = 0; i < length; i ++){
        scanf("%d", &input[i]);
    }

    while(1){
    int target;
        printf("\n請指定要查詢的數字: ");
        scanf("%d", &target);
        if(target <= 0){
            break;
        }

        int closet = input[0];
        int difference = target - input[0];
        for(int i = 1; i < length; i ++){
            if(target > input[i]){
                if(target - input[i] <= difference){ //差額相同時顯示較小的數字，因此是<=
                closet = input[i];
                difference = target - input[i];
                }
            }
            else{
                if(input[i] - target < difference){
                closet = input[i];
                difference = input[i] - target;
                }
            }
        }

        printf("最接近的數字: %d\n", closet);
    }
    return 0;

}

//  13 23 78 77 37 30 40 50 83 99