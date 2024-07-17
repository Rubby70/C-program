// 給定一個目標數字N 你要算出Fibonacci 數量的第N項第數字

// 0 1 1 2 3 5 8 13 21 34 55
// Fib[0] = 0
// Fib[1] = 1
// Fib[2] = Fib[0] + Fib[1] = 1
// Fib[3] = Fib[1] + Fib[2] = 2
// Fib[4] = Fib[2] + Fib[3] = 3
// Fib[N] = Fib[N - 2] + Fib[N - 1]

#include <stdio.h>


int Fibonacci(int, int[]);


int main(void){ //輸入負數可以停止程式 *********************

    int N;
    while(1){ 
        printf("\n請輸入N = ");
        scanf("%d", &N);
        if(N < 0){
            break;
        }

        int check[N + 1];
        for(int i = 0; i < (N + 1); i ++){
            check[i] = -1;
        }

        Fibonacci(N, check);
    }
    return 0;

}

int Fibonacci(int N, int check[]){
    
    if(check[N] == -1){ //如果還沒呼喚過這個函數，則計算Fib
        if(N == 0){
            check[0] = 0;
            printf("Fib[0] = 0\n");
            return 0;
        }
        else if(N == 1){
            check[1] = 1;
            printf("Fib[1] = 1\n");
            return 1;
        }
        int Fib = Fibonacci((N - 2), check)+ Fibonacci((N - 1), check);
        check[N] = Fib; //紀錄該N已經計算過
        printf("Fib[%d] = ", N);
        printf("Fib[%d] + Fib[%d] = ", N - 2, N - 1);
        printf("%d + %d = ", check[N - 2], check[N - 1]);
        printf("%d\n", Fib);
        return Fib;
    }
    else{ //若該N已經計算過，則指回傳FIB[N]的值，不重覆計算
        return check[N];
    }

}

