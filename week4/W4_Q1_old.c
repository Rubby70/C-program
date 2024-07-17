// 給你一個"排序好的"、"每個數字只會出現一次"的陣列，範圍會是0~2147483647 
// 妳的目標是要將數字統整在一起 如果有連續出現的數字，只要告訴我頭尾就好，而沒有跟人相連的數字就獨自表示
// Ex: 陣列 = [0, 1, 2, 4, 5, 7] 那你應該要輸出 ["0->2", "4->5", "7"]
//     陣列 = [0, 2, 3, 4, 6, 8, 9] 那妳應該要輸出 ["0", "2->4", "6", "8->9"]
#include "stdio.h"
#include "stdlib.h"
#include "time.h"


int main(void){

    //-----------------------------------------------------Part1.
    srand(time(0));
    int N;
    scanf("%d", &N);
    int rand_array[N];
    int confirm[2 * N + 1];
    for(int i = 0; i < N; i ++){
        rand_array[i] = -1;
    }
    for(int i = 0; i < (2 * N + 1); i ++){ 
        confirm[i] = 0;
    }
    for(int i = 0; i < N; i ++){
        while(rand_array[i] == -1){
            rand_array[i] = rand() % (2 * N + 1);
            if(confirm[rand_array[i]] == 1){
                rand_array[i] = -1;
                continue;
            }
            confirm[rand_array[i]] = 1;
        }
    }
    printf("Before rearrange:[ ");
    for(int i = 0; i < N; i ++){
        printf("%d ", rand_array[i]);
    }
    printf("]\n");
    //-----------------------------------------------------Part2.
    int temp_store;
    int adjusted = 0; //用來判斷是否已排列完畢
    int i;
    int j;
    while(!adjusted){
        for(i = 0; i < N;){
            for(j = i; j < N; j++){ //將數列由小排到大，會重複檢查數列中所有數字，並將最小值排在最右邊
                if(rand_array[i] > rand_array[j]){
                    temp_store = rand_array[i];
                    rand_array[i] = rand_array[j];
                    rand_array[j] = temp_store;
                    break;
                }
            }
            if(j == N){
                i ++;
            }
        }
        adjusted = 1;
    }
    printf("After rearrange:[ ");
    for(int i = 0; i < N; i ++){
        printf("%d ", rand_array[i]);
    }
    printf("]\n");
    //-----------------------------------------------------Part3.
    int everprint = 0; //是否印過箭頭
    printf("[ ");
    for(i = 1; i < N; i ++){
        if(rand_array[i] - rand_array[i - 1] == 1 && everprint == 0){
            printf("\"%d\"->", rand_array[i - 1]);
            everprint = 1;
        }
        else if(rand_array[i] - rand_array[i - 1] != 1){
            printf("\"%d\",", rand_array[i - 1]);
            everprint = 0;
        }
    }
    printf("\"%d\" ]\n", rand_array[N - 1]);
    return 0;
    
}