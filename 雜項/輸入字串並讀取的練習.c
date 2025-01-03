#include <stdio.h>


void scan_string(char []);

int main(void){

    char str[15];
    scan_string(str);
    printf("%s", str);
    return 0;

}

void scan_string(char str[]){

    int i = 0;
    while(1){
        scanf("%c", &str[i]);
        if(str[i] == '\n'){
            str[i] == '\0';
            break;
        }
        i ++;
    }

}