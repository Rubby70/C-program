// 猜數字遊戲 首先要先輸入 猜數字的範圍  (0~輸入的數字N)
// 接著就開始猜數字   每次使用者輸入數字之後  如果猜對了就結束程式 並印出猜對了!
// 猜錯了的話 如果猜錯的字數還不到5次 就要更新猜數字的範圍  
// 如果已經5次了  那就要說 很可惜  小笨蛋你沒機會囉   然後結束程式

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){

    srand(time(0));
    int N;
    printf("\n請指定範圍: 0 ~ ");
    scanf("%d", &N);
    if(N <= 0){
        printf("數字不符合規定\n\n");
        return 0;
    }
    int target = rand() % (N + 1); //目標數值介於 0 ~ N
    printf("目標數字: %d\n", target);
    
    int guess;
    int count = 0;
    int range_min = 0;
    int range_max = N;
    while(1){
        if(count == 5){ //猜滿5次則遊戲結束
            printf("但是很可惜 小笨蛋你沒機會囉\n\n");
            break;
        }
        printf("猜猜看目標數字是多少: ");
        scanf("%d", &guess);
        if(guess == target){
            printf("猜對了! 恭喜你 小可愛\n\n");
            break;
        }
        else if(guess != target){
            if(guess > target && range_max > guess){ //如果猜範圍外的數字就不改變範圍
                range_max = guess;
            }
            else if(guess < target && range_min < guess){
                range_min = guess;
            }
            printf("猜錯了! 還剩%d次機會。 目標數字介於%d ~ %d之間。\n", (4 - count), range_min, range_max);
            count ++;
        }
    }
    return 0;

}