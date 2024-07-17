// 生成隨機且不可以重複的資料集
#include "stdio.h"
#include "stdlib.h"
#include "time.h"


int main(void){

    srand(time(0));
    int N;
    scanf("%d", &N);
    int array[N]; //我實際要的數列
    int confirm[N]; //用來紀錄哪些數字已經出現過
    for(int i = 0; i < N; i ++){
        array[i] = 0;
        confirm[i] = 0;
    }
    for(int i = 0; i < N; i ++){
        while(array[i] == 0){
            array[i] = (rand() % N) + 1;
            if(confirm[array[i]] == 1){
            	array[i] = 0;
                continue;
            }
            confirm[array[i]] = 1;
        }
    }
    printf("array:[ ");
    for(int i = 0; i < N; i ++){
        printf("%d ", array[i]);
    }
    printf("]\n");
    return 0;

}