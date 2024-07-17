// 給定一個目標數字 N 你要把他轉成二進位印出來

#include <stdio.h>


int main(void){

    int N;
    while(1){
        printf("\n請指定目標數字N = ");
        scanf("%d", &N);
        if(N < 0){
            break;
        }

        int binary[32] = {0};
        int copyN = N;
        int i = 0;
        while(copyN > 0){
            if(copyN <= 3){
                if(copyN == 1){
                    binary[i] = 1;
                    break;
                }
                binary[i] = copyN % 2;
                binary[i + 1] = copyN / 2;
                i++;
                break;
            }
            binary[i] = copyN % 2;
            copyN /= 2;
            i ++;
        }
        printf("%d 轉成二進位有幾個數字: %d\n", N, i);

        printf("%d 轉成二進位: ", N);
        for(int j = i; j >= 0; j --){
            printf("%d", binary[j]);
        }
        printf("\n\n");
    }
    return 0;

}