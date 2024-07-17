// 螺旋矩陣 給你一個m x n的矩陣 按照順時針螺旋的順序 把矩陣中的元素印出來 
// Ex:

// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// 你應該要輸出 
// 1 2 3 6 9 8 7 4 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int n;
void rand_array(int [][n], int);
void print_array(int [][n], int);
void count_clockwise(int [][n], int);

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
	printf("\nA矩陣:\n");
    print_array(A, m); //印出矩陣A
	count_clockwise(A, m); //順時針印出矩陣內的數字
    return 0;
	
}

void rand_array(int array[][n], int m){

    int max_number = m * n; // 矩陣內出現的最大數字:
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            array[i][j] = -1;
        }
    }
    int confirm[m * n];
    for(int i = 0; i < (m * n); i ++){
        confirm[i] = -1;
    }
    int random;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            while(array[i][j] == -1){
                array[i][j] = rand() % max_number;
                if(confirm[array[i][j]] == 1){
                    array[i][j] = -1;
                    continue;
                }
                confirm[array[i][j]] = 1;
            }
        }
    }

}

void print_array(int array[][n], int m){

    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            printf("%3d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void count_clockwise(int array[][n], int m){

    int left = 0, right = n - 1, top = 0, bottom = m - 1;
    while(left <= right && top <= bottom){

        for(int i = left; i <= right; i ++){
            printf("%d ", array[top][i]);
        }
        top ++;

        for(int i = top; i <= bottom; i ++){
            printf("%d ", array[i][right]);
        }
        right --;

        if(top <= bottom){
            for(int i = right; i >= left; i --){
                printf("%d ", array[bottom][i]);
            }
            bottom --;
        }
        
        if(left <= right){
            for(int i = bottom; i >= top; i --){
                printf("%d ", array[i][left]);
            }
            left ++;
        }
    }
    printf("\n");

}
