#include <stdio.h>
#include <string.h>


int main(void){

    char input[100];
    char str[1000];
    char *str_pos[50] = {0};
    int length = 0;
    int size = 0;
    while(1){
        scanf("%s", input);
        if(strcmp(input, "END") == 0){
            break;
        }
        str_pos[length] = &(str[size]);
        strcpy(str_pos[length], input);
        size += strlen(input) + 1;
        length ++;
    }

    printf("------------\n");
    for(int i = 0; i < length; i ++){
        printf("%s ", str_pos[i]);
    }
    printf("\n");
    printf("(%d, %d)\n", length, size);
    return 0;

}