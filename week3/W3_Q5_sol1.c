// 生成隨機且不可以重複的資料集
#include "stdio.h"
#include "stdlib.h"
#include "time.h"


int main(void){

    srand(time(0));
    int N;
    scanf("%d", &N);
    int array[2*N]; //我實際要的數列
    int confirm[2*N]; //用來紀錄哪些數字已經出現過
    for(int i = 0; i < 2*N; i ++){
        array[i] = 0;
        confirm[i] = 0;
    }
    
    int previous_num = 0;
    for(int i = 0; i < N; i ++){
        while(array[i] == 0){
            array[i] = (rand() % (2*N)) + 1;
            if(previous_num > array[i]){
                array[i] = 0;
                continue;
            }
            confirm[array[i]] = 1;
            previous_num = array[i];
        }
    }
    printf("array:[ ");
    for(int i = 0; i < N; i ++){
        printf("%d ", array[i]);
    }
    printf("]\n");
    return 0;

}