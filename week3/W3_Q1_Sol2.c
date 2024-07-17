#include <stdio.h>



int main(void){

    int sum = 0;
    int input;

    // 這個應該是妳第一次看過的寫法XD 
    // 簡單來說 只要是函數，就一定有回傳值，scanf也不例外，所以我們也可以把scanf放進判斷式裡面判斷回傳值
    // 除此之外，想想看這一個判斷式的順序是否有意義，這跟我之前教過妳的某個概念有關
    // 加油  盡力想看看  回答出來會有小獵犬的專屬小禮物唷
    while(scanf("%d", &input) == 1 && input >= 0){
        sum += input;
    }
    
    printf("Sum is: %d\n", sum);
    return 0;

}