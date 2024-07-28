// 著名的 matched parentheses 
// 給你一個字串，這個字串只會由 "(“, “)”, "[", "]", "{", "}" 這三種刮號組成  
// 我們定義一組配對的刮號代表 (), [], {}是成對出現的 
// 告訴我給你的字串是否是配對的
// Ex: 
// (是不成對的
// ()是成對的
// []也是成對的 
// (]) 是不成對的
// ([]) 是成對的

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int scan_char(char **ptr2arr){

    int maximun = 0;
    int length;
    for(int i = 0; i >= 0; i ++){
        if(i == maximun){
            char *ptr2malloc = (char *)malloc(sizeof(char) * (maximun + 5));
            if(i > 0){
                strcpy(ptr2malloc, *ptr2arr);
                free(*ptr2arr);
            }
            *ptr2arr = ptr2malloc;
            maximun += 5;
        }
        scanf("%c", &((*ptr2arr)[i]));
        if((*ptr2arr)[i] == '\n'){
            (*ptr2arr)[i] = '\0';
            break;
        }
        length = i + 1;
    }
    return length;

}

void matched_parentheses(char **ptr2arr, int length){

    int check_order[3] = {0}; //條件1: 出現順序
    for(int i = 0; i < length; i ++){
        switch((*ptr2arr)[i]){
            case '(':
                check_order[0] ++;
                break;
            case '[':
                check_order[1] ++;
                break;
            case '{':
                check_order[2] ++;
                break;
            case ')':
                if(check_order[0] == 0){
                    break;
                }
                check_order[0] --;
                break;
            case ']':
                if(check_order[1] == 0){
                    break;
                }
                check_order[1] --;
                break;
            case '}':
                if(check_order[2] == 0){
                    break;
                }
                check_order[2] --;
                break;
        }
    }
    if(check_order[0] != 0){
        printf("不成對\n");
        return;
    }
    if(check_order[1] != 0){
        printf("不成對\n");
        return;
    }
    if(check_order[2] != 0){
        printf("不成對\n");
        return;
    }

    int check_count[6] = {0}; //條件2: 出現數量
    for(int i = 0; i < length; i ++){
        switch((*ptr2arr)[i]){
            case '(':
                check_count[0] ++;
                break;
            case '[':
                check_count[1] ++;
                break;
            case '{':
                check_count[2] ++;
                break;
            case ')':
                check_count[3] ++;
                break;
            case ']':
                check_count[4] ++;
                break;
            case '}':
                check_count[5] ++;
                break;
        }
    }
    if(check_count[0] != check_count[3]){
        printf("不成對\n");
        return;
    }
    if(check_count[1] != check_count[4]){
        printf("不成對\n");
        return;
    }
    if(check_count[2] != check_count[5]){
        printf("不成對\n");
        return;
    }

    int check[length]; //條件3: 有沒有被隔開
    for(int i = 0; i < length; i ++){
        check[i] = 0;
    }
    int site = length - 1;
    for(int i = 0; i < length; i ++){
        if(check[i] == 0){
            continue;
        }
        switch((*ptr2arr)[i]){
            case '(':
                for(int j = i + 1; j < length; j ++){
                    if(check[j] == 0){
                        continue;
                    }
                    if((*ptr2arr)[j] == ')'){
                        if(i < site && j > site){
                            printf("不成對\n");
                            return;
                        }
                        site = j;
                        check[i] = 0;
                        check[j] = 0;
                    }
                }
                break;
            case '[':
                for(int j = i + 1; j < length; j ++){
                    if(check[j] == 0){
                        continue;
                    }
                    if((*ptr2arr)[j] == ']'){
                        if(i < site && j > site){
                            printf("不成對\n");
                            return;
                        }
                        site = j;
                        check[i] = 0;
                        check[j] = 0;
                    }
                }
                break;
            case '{':
                for(int j = i + 1; j < length; j ++){
                    if(check[j] == 0){
                        continue;
                    }
                    if((*ptr2arr)[j] == '}'){
                        if(i < site && j > site){
                            printf("不成對\n");
                            return;
                        }
                        site = j;
                        check[i] = 0;
                        check[j] = 0;
                    }
                }
                break;
        }
    }
    printf("成對\n");
}

int main(void){

    char *arr = NULL;
    printf("請輸入字串: ");
    int length = scan_char(&arr); //掃描文字的函數
    printf("main函數中的arr: %s, 總字數:%d\n", arr, length);
    matched_parentheses(&arr, length);
    printf("\n");
    return 0;

}