// 我會給你一個數字, 範圍在1~2147483647之間，
// 你可以將這數字當中的 奇數與奇數交換，偶數與偶數交換，試著去祖出最大的數字

#include <stdio.h>
#include <math.h>


int count_digit_number(int); //計算總位數
int find_max_digit(int [], int); //挑出陣列中最大的數字
void determine_odd_even(int [], int [], int [], int, int);

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

    int odd[total_digit];
    int even[total_digit];
    int position[total_digit]; // 紀錄奇數與偶數的位置及數字
    determine_odd_even(odd, even, position, total_digit, input);

    printf("output: ");
    for(int i = total_digit - 1; i >= 0; i --){
        if(position[i] == 1){ //若該位置是奇數，則從奇數陣列中挑出最大的印出來
            printf("%d", find_max_digit(odd, total_digit));
        }
        else if(position[i] == 2){ //若是偶數，則從偶數陣列中挑最大的數字印出來
            printf("%d", find_max_digit(even, total_digit));
        }
    }
    printf("\n\n");
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

int find_max_digit(int Array[], int length){

    int max = -1;
    int temp; //用來暫存最大數字出現的位置
    for(int i = 0; i < length; i ++){
        if(Array[i] == -1){ //初始值設定為-1
            continue;
        }
        if(max < Array[i]){
            max = Array[i];
            temp = i;
        }
    }
    Array[temp] = -1; //找出最大的數字後，將該數字註記為-1，表示已經使用過了，下一次不能再用
    return max;

}

void determine_odd_even(int odd[], int even[], int position[], int length, int input){

    for(int i = 0; i < length; i ++){
        odd[i] = -1;
        even[i] = -1;
    }
    position[length]; // 紀錄奇數與偶數的位置及數字
    for(int i = length - 1, copy_input = input; i >= 0; i --){
        if((copy_input / (int)pow(10, i)) % 2 == 1){ //是奇數
            odd[i] = (copy_input / (int)pow(10, i)) % 10;
            position[i] = 1;
            printf("正在檢查的數字: %d", odd[i]);
        }
        else if((copy_input / (int)pow(10, i)) % 2 == 0){ //是偶數
            even[i] = (copy_input / (int)pow(10, i)) % 10;
            position[i] = 2;
            printf("正在檢查的數字: %d", even[i]);
        }
        printf("，判斷奇偶數: %d\n", position[i]);
    }

}