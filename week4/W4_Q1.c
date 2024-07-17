// 給你一個"排序好的"、"每個數字只會出現一次"的陣列
// 範圍會是0 ~ 2N 妳的目標是要將數字統整在一起 
// 如果有連續出現的數字，只要告訴我頭尾就好
// 而沒有跟人相連的數字就獨自表示

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_array(int [], int);
void rearrange(int [], int);
void array_initialize(int [], int);
void generate_no_repeat_array(int [], int);
void check_if_continue(int [], int);

int main(void){

    srand(time(0));
    int length;
    printf("\n請指定資料集大小: ");
    scanf("%d", &length);
    int A[length];
    generate_no_repeat_array(A, length); //產生數字不重複的資料集
    printf("\n隨機不重複資料集排序前:");
    print_array(A, length);

    rearrange(A, length); //將資料集按照大小排列
    printf("隨機不重複資料集排序後:");
    print_array(A, length);

    check_if_continue(A, length); //根據題目要求印出資料集
    printf("\n");
    return 0;

}

void print_array(int Array[], int length){

    printf("[ ");
    for(int i = 0; i < length ; i ++){
        printf("%d ", Array[i]);
    }
    printf("]\n");

}

void rearrange(int Array[], int length){
    for(int i = 0; i < length; i ++){
        for(int j = i; j < length; j ++){
            if(Array[i] > Array[j]){
                int temp = Array[i];
                Array[i] = Array[j];
                Array[j] = temp;
                // printf("排序中:");
                // print_array(Array, length);
            }
        }
    }
}

void array_initialize(int Array[], int length){

    for(int i = 0; i < length ; i ++){ //陣列初始化
        Array[i] = -1;
    }

}

void generate_no_repeat_array(int Array[], int length){

    array_initialize(Array, length); //資料集初始化

    int check[(2 * length + 1)]; // 資料集可能的數字涵蓋0 ~ 2N 因此要能夠應對check[2N]的情況
    array_initialize(check, (2 * length + 1)); //確認不重複的矩陣初始化

    for(int i = 0; i < length ; i ++){
        Array[i] = rand() % (2 * length + 1); // 範圍0 ~ 2N
        if(check[Array[i]] == 1){ //若Array[i]的數字已經出現過，則初始化重新生成亂數
            Array[i] = -1;
            i --;
        }
        else{
            check[Array[i]] = 1;
        }
    }

}

void check_if_continue(int Array[], int length){

    int if_continue = 0; //
    int previous_digit = -1;
    printf("\n題目要求的版本:[");
    for(int i = 0; i < length; i ++){
        if(if_continue == 0){ //如果目前沒有連續數字，則記錄現在的數字
            printf("%d ", Array[i]);
            if_continue = 1; //開始計算連續
            previous_digit = Array[i]; //用來存放等等讓A[i + 1]拿來比對的數字
            continue; //跳到下一個i
        }

        if(Array[i] == previous_digit + 1){ //如果A[i + 1] 和 A[i]連續，則i ++
            previous_digit ++;
            if_continue ++;
        }
        else{ //如果A[i + 1] 和 A[i]不連續
            if(if_continue > 1){ //如果前面是連續的數字，則印出箭頭
                printf("-> %d ", Array[i - 1]);
            }
            if_continue = 0; //初始化連續數字的第一項
            i --; //重新進到這個i，並回到第一個if
        }
    }
    printf("]\n");

}
