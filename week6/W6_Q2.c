// 把矩陣乘法的題目  全域變數的部分拔掉  改使用pointer的方式將陣列傳遞到函數當中
// 給你矩陣A, B A的尺寸是m x n, B的尺寸是 n x p. 回傳矩陣A,B的相乘結果  並以 m x p的形式印出
// Ex:  
// 2 3
// 1 2 3
// 4 5 6

// 3 2
// 7 8
// 9 10
// 11 12

// 你應該要輸出
// 58 64
// 139 154

#include <stdio.h>


void initialize(int *p[], int column, int row){

    for(int i = 0; i < column; i ++){
        for(int j = 0; j < row; j ++){
            p[i][j] = 1;
        }
    }

}

void print_array(int **p, int column, int row){

    for(int i = 0; i < column; i ++){
        for(int j = 0; j < row; j ++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

int main(void){

    // int m, n, p;
    // printf("請指定 m, n, p: ");
    // scanf("%d%d%d", &m, &n, &p);
    int A[2][3];
    int B[2][3];
    for(int i = 0; i < 2; i ++){
        for(int j = 0; j < 3; j ++){
            A[i][j] = 1;
            B[i][j] = 2;
        }
    }

    int *pB[2] = {B[0],B[1]};

    printf("A:\n");
    for(int i = 0; i < 2; i ++){
        for(int j = 0; j < 3; j ++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("B:\n");
    print_array(pB, 2, 3);

    return 0;

}

// void initialize(int *array [], int *column, int *row){

//     // int *array       是一個"指向陣列的指標"
//     // int *array []    是一個"指向陣列的指標的陣列"
//     for(int i = 0; i < *column; i ++){
//         for(int j = 0; j < *row; j ++){
//             array[i][j] = 0;
//         }
//     }

// }