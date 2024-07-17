#include <stdio.h>



int main(void){

    int sum = 0;
    int input;

    // 妳用do while的寫法 確實是能描繪出 至少需要讀取一次 這樣的需求
    // 但如果在裡面已經用一個判斷式做break的話  while迴圈的條件式是可以被簡化掉的
    // 這兩個寫法沒有誰優誰劣 我只是想要都給你看看而已
    while(1){ 
        scanf("%d", &input);
        if(input < 0){
            break;
        }
        sum += input;
    }
    
    printf("Sum is: %d\n", sum);
    return 0;
    
}