// 給你一個array，array的長度則為1~20的隨機一個數字，
// 這個array裡面只會含有1跟0兩種數字。找出這一個array當中，最多的連續的1是幾個

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_array(int [], int); //印矩陣
int count_continue(int [], int); //計算連續出現1次數

int main(void){

    srand(time(0));

    //int length = (rand() % 20) + 1; //題目要求的版本
    int length = 5; //改成固定數字方便檢查

    printf("\nArray Size = %d.\n", length);
    int A[length];
    for(int i = 0; i < length; i ++){
        A[i] = rand() % 2;
    }

    print_array(A, length);

    printf("最多連續出現次數: %d\n\n", count_continue(A, length));
    return 0;

}

void print_array(int Array[], int length){

    printf("Array:[ ");
    for(int i = 0; i < length; i ++){
        printf("%d ", Array[i]);
    }
    printf("]\n");

}

int count_continue(int Array[], int length){

    int count = 0;
    int max_count = 0;
    for(int i = 0; i < length; i ++){
        if(Array[i] == 0){
            count = 0;
        }
        else if(Array[i] == 1 && count >= 1){
            count ++;
        }
        else if(Array[i] == 1){
            count = 1;
        }

        if(max_count < count){
            max_count = count;
        }
        printf("被檢查的數字: A[%d] = %d , ", i, Array[i]);
        printf("目前的連續出現次數: %d\n", count);
    }
    return max_count;

}
