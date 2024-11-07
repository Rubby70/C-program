// 不使用sizeof 求出一個陣列的大小

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){

    srand(time(0));
    int length = (rand() % 20) + 1;
    int Array[length];
    for(int i = 0; i < length; i ++){
        Array[i] = rand() % 10;
    }
    // method 1 *************
    int size_1 = (&Array[length - 1] - &Array[0]) + 1;  

    // method 2 *************
    int *ptr_head_of_array = &Array[0];
    int *ptr_tail_of_array = &Array[length - 1];
    int size_2 = (ptr_tail_of_array - ptr_head_of_array) + 1;

    // method 3 *************
    printf("%ld\n", (int *)(&Array + 1) - (int *)&Array);

    printf("Array = [ ");
    for(int i = 0; i < length; i ++){
        printf("%d ", Array[i]);
    }
    printf("]\n");

    printf("實際矩陣大小(length) = %d\n", length);
    printf("用指標算出來的陣列大小= %d (method 1).\n", size_1);
    printf("用指標算出來的陣列大小= %d (method 2).\n", size_2);
    return 0;

}