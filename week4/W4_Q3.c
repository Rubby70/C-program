// 給定一個目標數字N 你要算出Fibonacci 數量的第N項第數字

// 0 1 1 2 3 5 8 13 21 34 55
// Fib[0] = 0
// Fib[1] = 1
// Fib[2] = Fib[0] + Fib[1] = 1
// Fib[3] = Fib[1] + Fib[2] = 2
// Fib[4] = Fib[2] + Fib[3] = 3
// Fib[N] = Fib[N - 2] + Fib[N - 1]

#include <stdio.h>


int Fibonacci(int);

int main(void){ //輸入負數可以停止程式 *********************

    int N;
    while(1){ 
        printf("請輸入N = ");
        scanf("%d", &N);
        if(N < 0){
            break;
        }
        
        printf("Fib[%d] = ", N);
        if(N >= 2){
            printf("Fib[%d] + Fib[%d] = ", N - 2, N - 1);
            printf("%d + %d = ", Fibonacci(N - 2), Fibonacci(N - 1));
        }
        printf("%d\n\n", Fibonacci(N));
    }
    return 0;

}

int Fibonacci(int N){
    
    if(N == 0){
        return 0;
    }
    else if(N == 1){
        return 1;
    }
    int Fib = Fibonacci(N - 2) + Fibonacci(N - 1);
    return Fib;

}

