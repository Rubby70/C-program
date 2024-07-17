	// 給你一個矩陣A，矩陣的尺寸是m x n輸出每一列跟每一行的矩陣元素的和先印出列，再印出行
	// Ex:    2 3
	// 	1 2 3
	// 	4 5 6  
	// 妳要輸出 6, 15, 5, 7, 9

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int n;
void rand_array(int [][n], int);
void print_array(int [][n], int);
void find_sum(int [][n], int);

int main(void){

    srand(time(0));
    int m;
    printf("請指定矩陣大小(m*n)\n");
    printf("列數(水平方向): m= ");
    scanf("%d", &m);
    printf("行數(垂直方向): n= ");
    scanf("%d", &n);
    int A[m][n];

    rand_array(A, m); //建立隨機且不重複的矩陣
    print_array(A, m); //印出矩陣A
    find_sum(A, m); //求矩陣內各行or列的總和

    return 0;

}

void rand_array(int A[][n], int m){ //建立隨機且不重複的矩陣

    int max_number = m * n; // 矩陣內出現的最大數字:
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            A[i][j] = -1;
        }
    }
    int confirm[m * n];
    for(int i = 0; i < (m * n); i ++){
        confirm[i] = -1;
    }
    int random;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            while(A[i][j] == -1){
                A[i][j] = rand() % max_number;
                if(confirm[A[i][j]] == 1){
                    A[i][j] = -1;
                    continue;
                }
                confirm[A[i][j]] = 1;
            }
        }
    }

}

void print_array(int A[][n], int m){ //印出矩陣A

    printf("\nA矩陣:\n");
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void find_sum(int A[][n], int m){ //求矩陣內各行or列的總和

    int sum_horizontal;
    int sum_vertical;
    for(int i = 0; i < m; i ++){
        printf("第%d列(水平方向)的總和= ", i);
        sum_horizontal = 0;
        for(int j = 0; j < n; j ++){
            sum_horizontal += A[i][j];
            if(j == n - 1){
                printf("%d ", A[i][j]);
            }
            else{
                printf("%d + ", A[i][j]);
            }
        }
        printf("= %d.\n", sum_horizontal);
    }
    printf("\n");
    for(int j = 0; j < n; j ++){
        printf("第%d行(垂直方向)的總和= ", j);
        sum_vertical = 0;
        for(int i = 0; i < m; i ++){
            sum_vertical += A[i][j];
            if(i == m - 1){
                printf("%d ", A[i][j]);
            }
            else{
                printf("%d + ", A[i][j]);
            }
        }
        printf("= %d.\n", sum_vertical);
    }

}