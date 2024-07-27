// 寫一個函數
// 輸入這個函數的參數是一個整數 
// 在函數中利用這個長度使用malloc建立一個整數陣列 
// 在不使用回傳值的情況下 要讓main函數接到這個pointer
// 然後讓這個陣列可以在main裡面使用（印出原有內容並排序）

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *build_array(int length){

    int *ptr = (int *)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i ++){
        ptr[i] = rand() % 10;
    }
    return ptr;

}

int main(void){

    srand(time(0));
    int length = 5;
    int *array = build_array(length);
    printf("排序前:[ ");
    for(int i = 0; i < length; i ++){
        printf("%d ", array[i]);
    }
    printf("]\n");

    for(int i = 0; i < length; i ++){
        for(int j = i; j < length; j ++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printf("排序後:[ ");
    for(int i = 0; i < length; i ++){
        printf("%d ", array[i]);
    }
    printf("]\n");
    return 0;

}

