// 寫出strstr函數
// 當我給你一個字串 str 以及一個目標字串str2 
// 告訴我目標str2字串是否存在在str當中
// 如果不存在  則回傳-1。 
// 存在的話就把他在str當中的位置印出來(0-indexed)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void string_scan(char *);

int main(void){

    char * str1 = 0; //建立一個叫做str1的字元指標
    //printf("初始字串可容納長度: 5\n");
    printf("請輸入字串1: ");
    //string_scan(str1);

    int length = 0; //預設字數為0個字元 (保留一格放\0)
    for(int i = 0; i >= 0; i ++){ //讀取輸入的所有字元
        if(i == length){ //若輸入的字數超過上限(預設為0)，則建立更大的字串
            int new_length = length + 5; //將字數上限提升5
            char *new_str = (char *)malloc(sizeof(char) * (new_length)); //利用malloc函數建立新字串
            if(length > 0){ //第一次的str1是空指標，所以不執行這一串動作
                strcpy(new_str, str1); //將原本str1內存放的字元搬到新的字串
                free(str1); //釋放原本的字串占用的記憶體空間
                printf("字串可容納長度更新: %d -> %d\n", length, new_length);
            }
            str1 = new_str; //將str1指標的記憶體位置變更到新字串的記憶體位置
            length = new_length; //透過指標修改字數上限
        }
        scanf("%c", &str1[i]);
        if(str1[i] == '\n'){ //讀取輸入的所有字元，直到出現換行
            str1[i] == '\0'; //將字串的最後一個字元填入\0
            break;
        }
        printf("目前掃描第幾個字: %d, 目前儲存的字串: %s\n", i + 1, str1);
    }


    // for(int i = 0; i != '\0'; i ++){
    //     printf("str1:%c", str1[i]);
    // }
    // printf("\n");
    printf("str1: %s\n", str1);
    return 0;

}

void string_scan(char * string){

    int length = 0; //預設字數為0個字元 (保留一格放\0)
    for(int i = 0; i >= 0; i ++){ //讀取輸入的所有字元
        if(i == length){ //若輸入的字數超過上限(預設為0)，則建立更大的字串
            int new_length = length + 5; //將字數上限提升5
            char *new_str = (char *)malloc(sizeof(char) * (new_length)); //利用malloc函數建立新字串
            if(length > 0){ //第一次的string是空指標，所以不執行這一串動作
                strcpy(new_str, string); //將原本string內存放的字元搬到新的字串
                free(string); //釋放原本的字串占用的記憶體空間
                printf("字串可容納長度更新: %d -> %d\n", length, new_length);
            }
            string = new_str; //將string指標的記憶體位置變更到新字串的記憶體位置
            length = new_length; //透過指標修改字數上限
        }
        scanf("%c", &string[i]);
        if(string[i] == '\n'){ //讀取輸入的所有字元，直到出現換行
            string[i] == '\0'; //將字串的最後一個字元填入\0
            break;
        }
        printf("目前掃描第幾個字: %d, 目前儲存的字串: %s\n", i + 1, string);
    }

}