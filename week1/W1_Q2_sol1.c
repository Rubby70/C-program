#include "stdio.h"
#include "math.h"


int main(void){

    int target_num;
    scanf("%d", &target_num);
    if(!target_num){
        printf("這個數字是 0\n");
        return 0;
    }
    int check_digits_amount = target_num;
    int digits_amount = 0;
    while(check_digits_amount){   // 在C語言中 "非零" 就是 "真"  "零" 就是 "假", 所以當我們直接把某個變數放在判斷式 代表我們期望他一開是是非零的
    // 順帶一提，如果我們希望進入判斷式的時候  該變數是 "零"  我們可以用 "!" 來取反, 也就是 while(!check_digits_amount) 這樣就可以達到目的了
        check_digits_amount /= 10;
        digits_amount++;
    }
    printf("這個數字有 %d 位數\n", digits_amount);
    /* 你看 上面我沒有使用到pow就確定了一個數字是幾位數XD */
    
    int processed_digit = 0;
    int processed_num = 0;
    while(processed_digit < digits_amount){ // 知道有幾位數  你甚至不需要把每個位數的情況分開寫，可以更通用的讓他  在每個digit 重複做(迴圈的用意)
        int current_digit = (target_num / (int)pow(10, processed_digit)) % 10;
        if(current_digit % 2 == 0)
            current_digit /= 2;
        processed_num += current_digit * (int)pow(10, processed_digit);
        processed_digit ++;
    }
    printf("處理後的數字是 %d\n", processed_num);
    return 0;

}

