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
#include <stdlib.h>
#include <time.h>


void initialize(int **p, int row, int column);
void random_array(int **p, int row, int column);
void print_array(int **p, int row, int column);
void mutiply_array(int **pA, int **pB, int **pC, int m, int n, int p);


int main(void){

    srand(time(0));
    int m, n, p;
    printf("依序指定m n p的值: ");
    scanf("%d%d%d", &m, &n, &p);

    int A[m][n];
    int *pA[m];
    for(int i = 0; i < m; i ++){
        pA[i] = A[i];
    }
    initialize(pA, m, n);
    random_array(pA, m, n);

    int B[n][p];
    int *pB[n];
    for(int i = 0; i < n; i ++){
        pB[i] = B[i];
    }
    initialize(pB, n, p);
    random_array(pB, n, p);

    int C[m][p];
    int *pC[m];
    for(int i = 0; i < m; i ++){
        pC[i] = C[i];
    }
    initialize(pC, m, p);
    mutiply_array(pA, pB, pC, m, n, p);

    printf("A: (%d * %d)\n", m, n);
    print_array(pA, m, n);
    printf("B: (%d * %d)\n", n, p);
    print_array(pB, n, p);
    printf("C: (%d * %d)\n", m, p);
    print_array(pC, m, p);
    return 0;

}

void initialize(int **p, int row, int column){

    for(int i = 0; i < row; i ++){
        for(int j = 0; j < column; j ++){
            p[i][j] = -1;
        }
    }

}

void random_array(int **p, int row, int column){

    int random_number;
    int check[row * column];
    for(int i = 0; i < (row * column); i ++){
        check[i] = -1;
    }
    for(int i = 0; i < row; i ++){
        for(int j = 0; j < column; j ++){
            while(p[i][j] == -1){
                p[i][j] = rand() % (row * column);
                if(check[p[i][j]] == -1){
                    check[p[i][j]] = 1;
                }
                else{
                    p[i][j] = -1;
                }
            }
        }
    }
    
}

void print_array(int **p, int row, int column){

    for(int i = 0; i < row; i ++){
        for(int j = 0; j < column; j ++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void mutiply_array(int **pA, int **pB, int **pC, int m, int n, int p){

    int rowA = 0;
    int rowB = 0;
    int rowC = 0;
    int columnA = 0;
    int columnB = 0;
    int columnC = 0;
    int multiply = 0;
    int valueC = 0;
    printf("\n矩陣相乘區:\n");
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < p; j ++){   
            for(int k = 0; k < n; k ++){
                int valueA = pA[rowA][columnA]; //取得矩陣A在該位置的值
                int valueB = pB[rowB][columnB]; //取得矩陣B在該位置的值
                multiply = valueA * valueB; //相乘
                printf("(%d*%d) %2d + ", valueA, valueB, multiply); //印出相乘的數字跟相乘的積
                valueC += multiply; //將乘積加起來
                rowB ++; //矩陣B換列
                columnA ++; //矩陣A換行
            }
            rowB = 0; //矩陣B 乘過的列數重置
            columnA = 0; //矩陣A 乘過的行數重置
            printf(", valueC = %d\n", valueC); //印出C要帶入什麼值
            pC[rowC][columnC] = valueC; //數值帶入矩陣C
            valueC = 0; //數值歸0繼續進行下一次乘法
            columnB ++; //矩陣A保持同一列，矩陣B換行
            columnC ++; //矩陣C換行
        }
        rowA ++; 
        columnB = 0;
        rowC ++;
        columnC = 0;
    }
    printf("\n");

}
