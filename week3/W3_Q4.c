// 生成隨機且不可以重複的資料集

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_array(int [], int);

int main(void){

    srand(time(0));
    int length;
    printf("請指定資料集大小: ");
    scanf("%d", &length);
    int A[length];
    int check[length];

    for(int i = 0; i < length ; i ++){ //陣列初始化
        A[i] = -1;
        check[i] = -1;
    }

    for(int i = 0; i < length ; i ++){
        A[i] = rand() % length;
        if(check[A[i]] == 1){ //若A[i]的數字已經出現過，則初始化重新生成亂數
            A[i] = -1;
            i --;
        }
        else{
            check[A[i]] = 1;
        }
    }

    printf("Array:");
    print_array(A, length);
    return 0;

}

void print_array(int Array[], int length){

    printf("[ ");
    for(int i = 0; i < length ; i ++){
        printf("%d ", Array[i]);
    }
    printf("]\n");

}