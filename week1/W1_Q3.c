// 輸入一個數字 (0~999) 把每個digits 轉成對應的英文字母

#include <stdio.h>
#include <math.h>


int main(void){

    int input;
    printf("\n");
    while(1){ // 若輸入數字不介於0~999則結束運行，否則持續運行
        printf("input: ");
        scanf("%d", &input);
        if(input < 0 || input > 999){
            printf("數字不在範圍內");
            printf("\n\n");
            break;
        }
        else if(input == 0){ // 0無法判斷位數，獨立條件
            printf("Output: a");
            printf("\n\n");
            continue;
        }

        int check_digit = input; //複製一份input用來計算位數
        int digit_num = 0; //紀錄共幾位數
        while(check_digit > 0){
            check_digit /= 10;
            digit_num ++;
        }
    
        printf("output: ");
        int current_digit;
        int store_digit[digit_num]; //建一個陣列存放處理完的數字
        for(int i = 0; i < digit_num; i ++){
            current_digit = (input / (int)pow(10, i)) % 10;
            store_digit[i] = current_digit + 97;
        }
        for(int i = digit_num - 1; i >= 0; i --){ //因為是從個位數開始處理，所以印出來順序要反過來
            printf("%c", store_digit[i]);
        }
        printf("\n\n");
    }
    return 0;

}