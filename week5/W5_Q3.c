// 矩陣乘法 
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


int n, p;
void rand_array_n(int [][n], int);
void rand_array_p(int [][p], int);
void print_array_n(int [][n], int);
void print_array_p(int [][p], int);
void multiply_matrix(int [][n], int [][p], int[][p], int);

int main(void){

    srand(time(0));
	int m;
    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);
	printf("p = ");
    scanf("%d", &p);
	printf("\n");

    int A[m][n];
    rand_array_n(A, m); //建立隨機且不重複的矩陣A
	printf("A矩陣: (%d * %d)\n", m, n);
    print_array_n(A, m); //印出矩陣A

	int B[n][p];
    rand_array_p(B, n); //建立隨機且不重複的矩陣B
	printf("B矩陣: (%d * %d)\n", n, p);
    print_array_p(B, n); //印出矩陣B

	int C[m][p];
	multiply_matrix(A, B, C, m);
	printf("C矩陣(值為A * B): (%d * %d)\n", m, p);
	print_array_p(C, m);
    return 0;
	
}

void rand_array_n(int array[][n], int row){

    int max_number = row * n; // 矩陣內出現的最大數字:
    for(int i = 0; i < row; i ++){
        for(int j = 0; j < n; j ++){
            array[i][j] = -1;
        }
    }
    int confirm[row * n];
    for(int i = 0; i < (row * n); i ++){
        confirm[i] = -1;
    }
    int random;
    for(int i = 0; i < row; i ++){
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

void rand_array_p(int array[][p], int row){

    int max_number = row * p; // 矩陣內出現的最大數字:
    for(int i = 0; i < row; i ++){
        for(int j = 0; j < p; j ++){
            array[i][j] = -1;
        }
    }
    int confirm[row * p];
    for(int i = 0; i < (row * p); i ++){
        confirm[i] = -1;
    }
    int random;
    for(int i = 0; i < row; i ++){
        for(int j = 0; j < p; j ++){
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

void print_array_n(int array[][n], int row){

    for(int i = 0; i < row; i ++){
        for(int j = 0; j < n; j ++){
            printf("%3d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void print_array_p(int array[][p], int row){

    for(int i = 0; i < row; i ++){
        for(int j = 0; j < p; j ++){
            printf("%3d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void multiply_matrix(int A[][n], int B[][p], int C[][p], int m){

	int rA = 0; // row A
	int rB = 0;
	int rC = 0;

	int cA = 0; // column A
	int cB = 0;
	int cC = 0;

	for(int i = 0; i < m; i ++){
		cB = 0;
		for(int j = 0; j < p; j ++){
			int sum = 0;
			cA = 0;
			rB = 0;
			for(int k = 0; k < n; k ++){
				sum += A[rA][cA] * B[rB][cB];
				cA ++;
				rB ++;
			}
			C[rC][cC] = sum;
			cB ++;
			cC ++;
		}
		rA ++;
	}

}