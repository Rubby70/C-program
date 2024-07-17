// 我會給你一個數字, 範圍在1~2147483647，這個數字只由6跟9組成。
// 告訴我 在"最多只能把一個digit從6換成9，或者9換成6的情況下"  你能組成的最大數字。

#include <stdio.h>
#include <math.h>


int count_digit_number(int); //計算總位數
int find_first_6(int, int); //尋找第一個六出現的位置
int change_6_to_9(int, int); //把6替換成9

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

    int position = find_first_6(input, total_digit);
    if(position == 0){
        printf("該數字沒有6\n\n");
        return 0;
    }
    else{
        printf("第一個6出現在第%d個數字\n", position);
    }

    printf("Output: %d\n\n", change_6_to_9(input, position));
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

int change_6_to_9(int input, int position){

    int output = input;
    output -= 6 * (int)pow(10, position - 1);
    output += 9 * (int)pow(10, position - 1);
    return output;

}
