#include <stdio.h>
#include <stdlib.h>


int main(void){

    int n;
    
    while(scanf("%d", &n) != 1){
        printf("error: invalid input\n");

        char c;
        while ((c = getchar()) != '\n');
    }
    printf("%d", n);
    return 0;

}