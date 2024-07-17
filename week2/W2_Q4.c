// 輸入一個數字, 範圍在1~2147483647，這個數字只由6跟9組成。
// 告訴我 在"最多只能把任意各一個6和9做交換的情況下"  你能組成的最大數字。

#include <stdio.h>
#include <math.h>


int count_digit_number(int); //計算總位數
int find_first_6(int, int); //尋找第一個6出現的位置
int find_least_9(int, int); //尋找最後一個9出現的位置
int exchange_6_9(int, int, int); //把其中一組6和9交換

int main(void){

    int input;
    printf("\ninput: ");
    scanf("%d", &input);
    if(input < 1){
        printf("數字不符合要求\n\n");
        return 0;
    }
    int total_digit = count_digit_number(input);
    printf("這是一個%d位數\n", total_digit);

    int position_6 = find_first_6(input, total_digit);
    int position_9 = find_least_9(input, total_digit);
    printf("第一個6的位置: %d, 最後一個9的位置: %d\n", position_6, position_9);
    printf("(3代表百位數字，1代表個位數字，0代表沒有該數字)\n\n");

    if(position_6 == 0 || position_9 == 0){ //沒有6或9則無法交換
        printf("該輸入數字無法做數字交換\n\n");
        return 0;
    }
    else if(position_6 < position_9){ //若已經是最大的組合則不需交換
        printf("該輸入數字不需要數字交換\n");
        printf("Output: %d\n\n", input);
    }
    else{
        printf("Output: %d\n\n", exchange_6_9(input, position_6, position_9));
    }
    return 0;
    
}

int count_digit_number(int input){

    int copy_input = input;
    int total_digit = 0;
    while(copy_input > 0){
        copy_input /= 10;
        total_digit ++;
    }
    return total_digit;

}

int find_first_6(int input , int total_digit){

    int position = 0;
    for(int i = total_digit - 1, copy_input = input; i >= 0; i --){
        if ((copy_input / (int)pow(10, i)) % 10 == 6){
            position = i + 1;
            break;
        }
    }
    return position;

}

int find_least_9(int input, int total_digit){

    int position = 0;
    for(int i = total_digit - 1, copy_input = input; i >= 0; i --){
        if ((copy_input / (int)pow(10, i)) % 10 == 9){
            position = i + 1;
        }
    }
    return position;

}

int exchange_6_9(int input, int position_6, int position_9){

    int output = input;
    output -= 6 * (int)pow(10, position_6 - 1); //原本的6換成9
    output += 9 * (int)pow(10, position_6 - 1); //扣掉6，加9回去

    output -= 9 * (int)pow(10, position_9 - 1); //原本的9換成6
    output += 6 * (int)pow(10, position_9 - 1); //扣掉9，加6回去
    return output;

}
