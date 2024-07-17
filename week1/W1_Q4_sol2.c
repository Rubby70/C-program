/**
 * @file datasets generation
 * @author Rubby_is_the_cutest_princess@Louis_home.com
 * @brief a little program performing datasets generation for my dear
 * @version 0.1
 * @date 2024-06-09
 * 
 * @copyright Copyright (c) 2024 only for Rubby, otherwise you should pay me a lot!
 * 
 */
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"



int main(void){

    srand(time(0)); // 這個是為了讓rand() 在每次實行的時候都能有不同的數字
    int array_size;
    scanf("%d", &array_size);

    int array[array_size];  // 這個是用來存放我們要的數字的
    int generated_number[array_size + 2];   // 這個是在生成資料的時候用來檢查我們有沒有重複的數字
    for(int i = 0; i <= (array_size + 1); i ++){ // 因為範圍是 [1 ~ array_size] 所以要多一個 所以這個陣列長度會比實際長度多1
        generated_number[i] = 0;
    }

    

    int filled_amount = 0;
    while(filled_amount < array_size){
        int rand_num = (rand() % (array_size + 1)) + 1; // 生成[1, array_size+1]的數字
        if(generated_number[rand_num] == 0){    // 如果這個數字還沒有被生成過
            array[filled_amount] = rand_num;
            generated_number[rand_num] = 1;     // 這個數字已經被生成過了
            filled_amount ++;                   // 這個數字已經被放進去了
        }
        else{
            continue;                           // 如果這個數字已經被生成過了，那就重新生成下一個
        }
    }

    for (int i = 0; i < array_size; i ++){
        printf("%d ", array[i]);
    }
    printf("\n");

    /*start solving the problem*/
    int occur_times[array_size + 2];        // 觀察變數出現的次數  是個很常見的技巧，在我們確定 每個變數只能出現一次的情況下，紀錄變數的頻率可以做到很多事情唷
    for(int i = 0; i <= (array_size + 1); i ++){
        occur_times[i] = 0;
    }
    for(int i = 0; i < array_size; i ++){
        occur_times[array[i]] ++;           // 把從其他array提取出來的資料拿來作為index是另一個常見的技巧, 這種 "查找表" 的技巧在很多地方都會用到
    }
    for(int i = 1; i <= (array_size + 1); i ++){
        if(occur_times[i] == 0){            // 消失的數字代表沒出現過
            printf("The missing number is %d\n", i);
            break;
        }
    }
    return 0;
    
}