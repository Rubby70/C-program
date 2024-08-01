// 著名的josephus problem 
// 給一個長度為N的陣列 代表有N個人 
// 給你一個起始點P 以及間隔K 
// 從第P個人開始算 每次數到K個人之後 把他殺掉 
// 並從被殺掉的人的下一個人開始計算 直到只剩下1個人 
// 請問最後剩下的人 是編號幾的人
// N > 1 & P < N

#include <stdio.h>


int josephus(int array[], int N, int P, int K, int alive, int round, int total){

    if(alive == 1){ //當總存活人數剩下1時結束遞迴
        printf("版本1: ");
        for(int i = 0; i < N; i ++){ //用for loop去找還活著的那個人是誰
            if(array[i] == 1){
                printf("剩下編號%d存活(編號由0 ~ %d)\n", i, N - 1);
            }
        }

        printf("版本2: "); //用等差數列公式去找誰還活著
        printf("剩下編號%d存活(編號由0 ~ %d)\n", total, N - 1);
        return 0;
    }

    printf("***第%d回合, 從編號 %d 開始, 往後找%d位然後殺掉***, \n", round, P, K);
    printf("剩餘存活編號:[ ");
    for(int i = 0; i < N; i ++){
        if(array[i] == 1){
            printf("%d ", i);
        }
    }
    printf("], ");

    int count = 0; //計數器，用來數到K
    while(count != K){ //若還沒數K次，則P++
        P ++;
        if(P > (N - 1)){ //若P超過最大人數則重頭數
            P = 0;
        }
        if(array[P] == 0){ //若這個人已經殺過就跳過
            continue;
        }
        count ++; //若這個人還活著就有算次數
    }
    array[P] = 0; //找到指定的P後殺掉
    alive --; //殺掉後存活人數-1
    round ++; //回和數 +1
    total -= P; //用來找最後剩下誰
    printf("編號%d淘汰, 剩下%d個人\n\n", P, alive);

    while(array[P] == 0){ //用來找下一輪要從誰開始數
        P ++;
        if(P > (N - 1)){
            P = 0;
        }
    }

    josephus(array, N, P, K, alive, round, total);
    return 0;

}

int main(void){

    int N, P, K;
    printf("請依序指定N, P, K: ");
    scanf("%d%d%d", &N, &P, &K);
    int array[N];
    for(int i = 0; i < N; i ++){
        array[i] = 1; //陣列內的數值是1代表存活
    }
    int alive = N; //初始總存活人數N個
    int round = 1; //計算回和數
    int total = (0 + (N - 1) * N / 2); //用來找最後剩下誰
    printf("總人數: %d, 每次間隔: %d\n", N, K);
    josephus(array, N, P - 1, K, alive, round, total);
    return 0;

}

// 10 2 4