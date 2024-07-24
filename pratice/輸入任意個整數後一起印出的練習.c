#include <stdio.h>
#include <stdlib.h>


int main(void){

    int *numbers = 0;
    int length = 0;

    while(1){
        int input;
        printf("請輸入數字: ");
        scanf("%d", &input);
        if(input == 0){
            break;
        }
        numbers = realloc(numbers, sizeof(int) * (length + 1));
        // int *larger = malloc(sizeof(int) * (length + 1));
        // for(int i = 0; i < length; i ++){
        //     larger[i] = numbers[i];
        // }
        // free(numbers);

        numbers[length] = input;
        length ++;
    }

    printf("\nNumbers: ");
    for(int i = 0; i < length; i ++){
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;

}