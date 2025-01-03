// 3. 猜數字遊戲
// 首先要先輸入 猜數字的範圍  (0~輸入的數字N)
// 接著就開始猜數字   每次使用者輸入數字之後  如果猜對了就結束程式 並印出猜對了!
// 猜錯了的話 如果猜錯的字數還不到5次 就要更新猜數字的範圍  如果已經5次了  那就要說 很可惜  小笨蛋你沒機會囉   然後結束程式
// Ex: 輸入 100 表示從0~100 隨機生成一個目標數字
// 假設生成了68
// 使用者輸入50 --> 猜錯了  再試試看吧 數字範圍50~100
// 使用者輸入51 --> 猜錯囉 再試試看吧 數字範圍51~100
// 使用者輸入71 --> 猜錯囉 再試試看吧 數字範圍51~71
// 使用者輸入61 --> 猜錯囉 再試試看吧 數字範圍61~71
// 使用者輸入62 --> 又猜錯了 很可惜 小笨蛋你沒機會囉
// 使用者輸入68 -->  賓果!  不愧是我的小可愛呢 答對囉!
#include "stdio.h"
#include "stdlib.h"
#include "time.h"


int main(void){
    
    int N;
    printf("小獵犬請先輸入最大數字: ");
    scanf("%d", &N);
    printf("目前數字範圍: 0 ~ %d.\n", N);

    srand(time(0));
    int rand_num = (rand() % N) + 1; //生成範圍在1 ~ N之間的隨機數字
    int answer = rand_num; //目標數字由亂數產生
    printf("answer= %d (猜對才可以抱抱，所以偷偷告訴你答案)\n", answer);
    int guess; //玩家輸入猜測的數字
    int min = 0, max = N;
    for(int cnt1 = 1; cnt1 <= 5; cnt1 ++){
        scanf("%d", &guess);
        if(guess > answer){
            max = guess;
            printf("猜錯囉 再試試看吧 數字範圍%d~%d\n", min, max);
        }
        else if(guess < answer){
            min = guess;
            printf("猜錯囉 再試試看吧 數字範圍%d~%d\n", min, max);
        }
        else if(guess == answer){
            printf("賓果! 不愧是我的小獵犬呢 答對囉!\n");
            return 0;
        }
    }
    printf("又猜錯囉 很可惜 小獵犬你沒機會囉\n");
    return 0;

}