// 給定一個長度為n的array， array中的數字是[1,n+1] 美個數字只會出現一次，找出不在array中的數字

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Array_Initialize(int [], int); //將陣列初始化成0
void Generate_Random_Array(int [], int); //產生隨機陣列
void Print_Array(int [], int);  //印出矩陣
int Find_Missing_number(int [], int); //尋少缺少的數字

int main(void){

    srand(time(0));
    int n;
    scanf("%d", &n);

    int A[n];
    Array_Initialize(A, n);
    Generate_Random_Array(A, n);

    printf("A陣列:");
    Print_Array(A, n);

    printf("缺少的數字是: %d\n", Find_Missing_number(A, n));
    
    return 0;

}

void Array_Initialize(int array[], int count){

    for(int i = 0; i < count; i ++){
        array[i] = 0;
    }

}

void Print_Array(int array[], int count){

    printf("[ ");
    for(int i = 0; i < count; i ++){
        printf("%d ", array[i]);
    }
    printf("]\n");

}

void Generate_Random_Array(int array[], int count){

    int check[count + 2]; //因為A陣列可能的數字為1~n+1 => 所以要有n+2項
    Array_Initialize(check, (count + 2));
    for(int i = 0; i < count; i ++){
        while(array[i] == 0){
            array[i] = (rand() % (count + 1) ) + 1;
            if(check[ array[i] ] == 1){
                array[i] = 0;
                continue;
            }
            check[ array[i] ] = 1;
        }
    }

}

int Find_Missing_number(int array[], int count){

    int missing;
    int sum;
    sum = (1 + (count + 1) ) * (count + 1) / 2;
    for(int i = 0; i < count; i ++){
        sum -= array[i];
    }
    missing = sum;
    return missing;

}