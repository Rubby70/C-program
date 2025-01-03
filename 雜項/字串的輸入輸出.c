#include <stdio.h>


int main(void){

    //輸入方式1.
    char strA[] = {'H','e','l','l','o',' ','W','o','r','l','d','\0'};
    for(int i = 0; strA[i] != '\0'; i ++){
        printf("%c", strA[i]);
    }
    printf("\n");

    //輸入方式2.
    char strB[] = "Hello World 2";
    for(int i = 0; strB[i] != '\0'; i ++){ //輸出方式1.
        printf("%c", strB[i]);
    }
    printf("\n");

    printf("%s\n", strB); //輸出方式2.

    return 0;

}