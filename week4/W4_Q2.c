// 給你一個"排序好的"的陣列，範圍會是0 ~ 2N，這次在陣列當中的數字"是可以重複出現的"
// 妳的目標是 將陣列當中 重複出現的數字 刪除到只剩下一個，並且刪除後，為了要維持陣列長度不變，妳要在後面補_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_array(int [], int);
void rearrange(int [], int);
void generate_random_array(int [], int);
void delete_repeat_digit(int [], int);

int main(void){

    srand(time(0));
    int length;
    printf("\n請指定資料集大小: ");
    scanf("%d", &length);
    int A[length];
    generate_random_array(A, length);
    printf("\n隨機資料集排序前:");
    print_array(A, length);

    rearrange(A, length); //將資料集按照大小排列
    printf("隨機資料集排序後:");
    print_array(A, length);
    printf("\n");

    delete_repeat_digit(A, length); //刪除重複的數字
    printf("\n資料集整理後:[ ");
    int count = 0;
    for(int i = 0; i < length ; i ++){
        if(A[i] == -1){ // -1代表原本的數字被刪除了，紀錄總共刪了幾個
            count ++;
            continue;
        }
        printf("%d ", A[i]);
    }
    for(int j = 0; j < count; j ++){ //將被刪除的數字換成底線印出來
            printf("_ ");
    }
    printf("]\n\n");
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
                // printf("排序中:");
                // print_array(Array, length);
            }
        }
    }
}

void generate_random_array(int Array[], int length){

    for(int i = 0; i < length ; i ++){ //陣列初始化
        Array[i] = rand() % (2 * length + 1);
    }

}

void delete_repeat_digit(int Array[], int length){

    int previous_digit = -1;
    for(int i = 0; i < (length); i ++){
        if(Array[i] == previous_digit){ //若是出現重複的數字，那就把這個數字刪除，把最後一項往前面丟
            Array[i] = -1;
            printf("目前檢查的數字:A[%2d], 整理中的資料集:", i); //這個東西是方便讓你看看我刪除重複的過程
            print_array(Array, length);
            continue;
        }
        previous_digit = Array[i];
        printf("目前檢查的數字:A[%2d], 整理中的資料集:", i); //這個也是方便你檢查
        print_array(Array, length);
    }

}
