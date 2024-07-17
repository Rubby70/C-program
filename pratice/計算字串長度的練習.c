#include <stdio.h>


int main(void){

    char string[] = "Hello World";
    int i = 0;
    while(string[i] != '\0'){
        i ++;
    }

    printf("\n");
    printf("字串: %s\n", string);
    printf("使用迴圈計算字串長度: %d\n", i);
    printf("使用sizeof函數計算字串長度: %ld\n", sizeof(string));
    printf("\n");
    return 0;

}