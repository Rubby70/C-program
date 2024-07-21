// 寫出strstr函數
// 當我給你一個字串 str 以及一個目標字串str2 
// 告訴我目標str2字串是否存在在str當中
// 如果不存在則回傳-1
// 存在的話就把他在str當中的位置印出來(0-indexed)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void string_scan(char **); //讀取輸入的文字
int count_string(char *); //計算字串總字數
void ststst(char *, char *, int, int);

int main(void){

    printf("\n");
    char *str1; //建立一個叫做str1的字元指標
    printf("請輸入字串1: ");
    string_scan(&str1); //讀取輸入的字串
    int length1 = count_string(str1); //紀錄str1有幾個字
    
    char *str2;
    printf("請輸入字串2: ");
    string_scan(&str2); //讀取輸入的字串
    int length2 = count_string(str2); //紀錄str2有幾個字

    printf("str1 = %s ,共有%d個字\n", str1, length1);
    printf("str2 = %s ,共有%d個字\n", str2, length2);

    ststst(str1, str2, length1, length2);
    return 0;

}

void string_scan(char **string){

    int length = 0; //預設字數為0個字元
    for(int i = 0; i >= 0; i ++){ //讀取輸入的所有字元
        if(i == length){ //若輸入的字數超過上限，則建立更大的字串
            int new_length = length + 5; //將字數上限提升5
            char *new_str = (char *)malloc(sizeof(char) * (new_length)); //利用malloc函數建立新字串
            if(length > 0){ //第一次的string是空指標，所以不執行這一串動作
                strcpy(new_str, *string); //複製原本的保存的內容到新的字串
                free(*string); //釋放上一個字串占用的記憶體空間
                //printf("字串可容納長度更新: %d -> %d\n", length, new_length);
            }
            *string = new_str; //將指標指向的記憶體位置變更到新字串的記憶體位置
            length = new_length; //紀錄修改後的字數上限
        }
        scanf("%c", &(*string)[i]);
        if((*string)[i] == '\n'){ //讀取輸入的所有字元，直到出現換行
            (*string)[i] = '\0'; //將字串的最後一個字元改成\0
            break;
        }
        //printf("目前掃描第幾個字: %d, 目前儲存的字串: %s\n", i + 1, string);
    }

}

int count_string(char * string){

    int number = 0;
    while(1){
        if(string[number] == '\0'){
            break;
        }
        number ++;
    }
    return number;

}

void ststst(char *str1, char *str2, int length1, int length2){

    int count = 0;
    int start = 0; 
    for(int i = 0; i >= 0; i ++){
        if(i > length1){ //若i超過str1的總字數則停止
            printf("=> -1");
            break;
        }
        //printf("i= %d, count數: %d\n", i, count);
        if(str1[i] == str2[count]){ //判斷字元是否相同
            if(count == 0){ //只記錄開始出現的位置
                start = i;
            }
            count ++;
            if(count == length2){ //若滿足str2的字數則判斷存在
                printf("=> %d", start);
                break;
            }
        }
        else{ //若字元不相同則計數歸零
            count = 0; 
        }
    }
    printf("\n\n");

}
