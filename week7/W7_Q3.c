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
    //Ex: ({)} -> 不成對, (){} -> 成對
    // ({[(])})      X
    // ()[]({})      V
    // (({}[]))      V
int find(char **ptr2arr, int *ptr2check, int length, int current_position, char A){

    int target_position = -1;
    int previous = 1000;
    for(int i = 0; i < current_position; i ++){
        printf("   ");
    }
    printf("進入%d層遞迴", current_position);
    printf(", 目前的字元:\"%c\"", (*ptr2arr)[current_position]);
    printf(", current_position: %d\n", current_position);
    for(int i = (current_position + 1); i < length; i ++){
        if(ptr2check[i] == 1 && ((*ptr2arr)[i] == '(' || (*ptr2arr)[i] == '[' || (*ptr2arr)[i] == '{')){
            previous = find(ptr2arr, ptr2check, length, i, (*ptr2arr)[i]);
        }
        if(ptr2check[current_position] == 1){
            switch((*ptr2arr)[current_position]){
                case '(':
                    if((*ptr2arr)[i] == ')' && ptr2check[i] == 1){
                        target_position = i;
                        if(target_position > previous){
                            printf("不成對\n");
                            return 0;
                        }
                        ptr2check[current_position] = 0;
                        ptr2check[target_position] = 0;
                        printf("找到成對(): %c,%c\n", (*ptr2arr)[current_position], (*ptr2arr)[target_position]);
                        break;
                    }
                case '[':
                    if((*ptr2arr)[i] == ']' && ptr2check[i] == 1){
                        target_position = i;
                        if(target_position > previous){
                            printf("不成對\n");
                            return 0;
                        }
                        ptr2check[current_position] = 0;
                        ptr2check[target_position] = 0;
                        printf("找到成對[]: %c,%c\n", (*ptr2arr)[current_position], (*ptr2arr)[target_position]);
                        break;
                    }
                case '{':
                    if((*ptr2arr)[i] == '}' && ptr2check[i] == 1){
                        target_position = i;
                        if(target_position > previous){
                            printf("不成對\n");
                            return 0;
                        }
                        ptr2check[current_position] = 0;
                        ptr2check[target_position] = 0;
                        printf("找到成對{}: %c,%c\n", (*ptr2arr)[current_position], (*ptr2arr)[target_position]);
                        break;
                    }
            }
        }
    }
    for(int i = 0; i < current_position; i ++){
        printf("   ");
    }
    printf("離開%d層遞迴\n", current_position);
    return target_position;

}

void matched_parentheses(char **ptr2arr, int length){

    //條件1: 出現順序(是否遵循先左括號才右括號)
    //Ex: )([] -> 不成對, ()[] -> 成對
    int check_order[3] = {0}; 
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
    //條件2: 出現數量(括號是否成對出現)
    //Ex: ()[ -> 不成對, ()[] -> 成對
    int check_count[6] = {0}; 
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
    //條件3: 括號是否在相同區間內
    //Ex: ({)} -> 不成對, (){} -> 成對
    // ({[(])})      X
    // ()[]({})      V
    // (({}[]))      V
    // (*ptr2arr)[i];
    int check[length];
    int *ptr2check = check;
    for(int i = 0; i < length; i ++){
        check[i] = 1;
    }
    find(ptr2arr, ptr2check, length, 0, (*ptr2arr)[0]);
    printf("check: ");
    for(int i = 0; i < length; i ++){
        printf("%d ", check[i]);
    }
    printf("\n");
    // for(int i = 0; i < length; i ++){
    //     if(check[i] = 0){
    //         printf("不成對\n");
    //         return;
    //     }
    // }
    // printf("成對\n");
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