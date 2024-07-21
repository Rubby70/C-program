// 寫出strstr函數
// 當我給你一個字串 str 以及一個目標字串str2 
// 告訴我目標str2字串是否存在在str當中
// 如果不存在  則回傳-1。 
// 存在的話就把他在str當中的位置印出來(0-indexed)

#include <stdio.h>
#include <stdlib.h>


int main(void){

    int length = 5; //預設字數為5個字元
    int *length_location = &length; //建立一個指向字數的指標
    
    char str1[length]; //建立一個大小為5(預設尺寸)的str1陣列
    printf("請輸入字串1: ");
    for(int i = 0; i >= 0; i ++){ //讀取輸入的所有字元

        if(i == *length_location){ //若累積輸入的字數超過上限(預設為5)，則建立更大的字串
            int new_length = *length_location + 5; //將總字數上限提升5
            char *new_str = (char *)malloc(sizeof(char) * (new_length)); //利用malloc函數建立新字串
            for(int j = 0; j < new_length; j ++){
                new_str[j] = str1[i]; //將原本str1字串內存放的字元搬到新的字串
            }
            free(str1); //釋放原本的字串占用的記憶體空間
            str1 = new_str; //將str1引導到新字串的記憶體位置
            *length_location = new_length; //透過指標修改目前的字數上限值
        }

        scanf("%c", &str1[i]);

        if(str1[i] == '\n'){ //讀取輸入的所有字元，直到出現換行
            str1[i] == '\0'; //將字串的最後一個字元填入\0
            break;
        }
    }
    printf("輸入的字串: %s\n", str1);
    return 0;

}