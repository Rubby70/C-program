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

	int check[m][n]; //用來確認矩陣中哪個位置被印過的check矩陣 (尺寸與傳入矩陣相同)
	for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            check[i][j] = 0;
        }
    }
	int count = 1; //紀錄總共印了幾個數字，count總數應為m*n
	int cycle = 0; //順時鐘繞一圈為一個cycle
	int side = 1; //用來判斷正在數矩陣的上下左右的哪一個邊
	int i, j;
	while(count <= (m * n)){ //當印的次數小於m*n則繼續印
		switch(side){ //判斷正在數哪一個邊
			/* 
						m = 4 , n = 4
						
					(0,0) (0,1) (0,2) (0,3)
					(1,0) (1,1) (1,2) (1,3)
					(2,0) (2,1) (2,2) (2,3)
					(3,0) (3,1) (3,2) (3,3)			
			*/
			case 1:{ //上邊
				for(j = (0 + cycle); j < (n - cycle); j ++){
					i = 0 + cycle;
					printf("%d ", array[i][j]);
					check[i][j] += 1;
					count ++;
				}
				side ++;
				break;
			}
			case 2:{ //右邊
				for(i = (1 + cycle); i < (m - cycle); i ++){
					j = n - 1 - cycle;
					printf("%d ", array[i][j]);
					check[i][j] += 1;
					count ++;
				}
				side ++;
				break;
			}
			case 3:{ //下邊
				for(j = (n - 2 - cycle); j >= (0 + cycle); j --){
					i = m - 1 - cycle;
					printf("%d ", array[i][j]);
					check[i][j] += 1;
					count ++;
				}
				side ++;
				break;
			}
			case 4:{ //左邊
				for(i = (m - 2 - cycle); i >= (0 + 1 + cycle); i --){
					j = 0 + cycle;
					printf("%d ", array[i][j]);
					check[i][j] += 1;
					count ++;
				}
				cycle ++;
				side = 1;
				break;
			}	
		}
	}
	printf("\n\ncheck矩陣(有被印過的顯示1):\n");
	print_array(check, m);

}
