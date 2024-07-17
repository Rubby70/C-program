// 給你一個array，array的長度則為1~20的隨機一個數字，這個array裡面只會含有1跟0兩種數字。找出這一個array當中，最多的連續的1是幾個
// Ex: [1,1,0,1,1,1] <--- 給你這個array 你要回傳3 因為最多連續出現的1是3次
#include "stdio.h"
#include "stdlib.h"
#include "time.h"


int main(void){

//-----------------------------------------------------------------------
//產生隨機0或1並放入陣列
    srand(time(0)); //這個是為了讓rand() 在每次實行的時候都能有不同的數字
    int array_size;
    scanf("%d", &array_size);
    printf("The array size is: %d.\n", array_size);
    int array[array_size];
    int filled_amount = 0;
    while(filled_amount < array_size){
        int rand_num = (rand() % 2); //生成0或1的數字
        array[filled_amount] = rand_num; //填入陣列
        filled_amount ++; //重複執行array_size次 (例如0~19共20次)
    }
    printf("The array are:[ ");
    for (int i = 0; i < array_size; i ++){
        printf("%d ", array[i]);
    }
    printf("].\n");
    int cnt = 0;
    int max_cnt = 0;
    for(int i = 0; i < array_size; i++){
        if(array[i] == 1){
            cnt ++;
            if(max_cnt < cnt)
                max_cnt = cnt;
        }
        else
            cnt = 0;
    }    
    
    printf("The max continuous 1 is: %d.\n", max_cnt);
    return 0;
    
}