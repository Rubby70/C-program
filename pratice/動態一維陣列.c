#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){

    int length = 0;
    char *ptr_input = 0;
    for(int i = 0; i <= length; i ++){
        if(i == length){
            length += 5;
            char *ptr_malloc = malloc(sizeof(char) * length);
            if(i != 0){
                strcpy(ptr_malloc, ptr_input);
                free(ptr_input);
            }
            ptr_input = ptr_malloc;
        }
        scanf("%c", &ptr_input[i]);
        if(ptr_input[i] == '\n'){
            ptr_input[i] = '\0';
            break;
        }
    }
    printf("%s\n", ptr_input);
    return 0;

}