// 生成隨機且可以重複 但是要排序好的資料集

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_array(int [], int);
void rearrange(int [], int);

int main(void){

    srand(time(0));
    int length;
    printf("\n請指定資料集大小: ");
    scanf("%d", &length);
    int A[length];
    for(int i = 0; i < length ; i ++){
        A[i] = rand() % length;
    }
    printf("\n排序前:");
    print_array(A, length);
    printf("\n");

    rearrange(A, length);

    printf("\n排序後:");
    print_array(A, length);
    printf("\n");
    return 0;

}

void print_array(int Array[], int length){

    printf("[ ");
    for(int i = 0; i < length ; i ++){
        printf("%d ", Array[i]);
    }
    printf("]\n");

}

void rearrange(int Array[], int length){
    for(int i = 0; i < length; i ++){
        for(int j = i; j < length; j ++){
            if(Array[i] > Array[j]){
                int temp = Array[i];
                Array[i] = Array[j];
                Array[j] = temp;
                printf("排序中:");
                print_array(Array, length);
            }
        }
    }
}
