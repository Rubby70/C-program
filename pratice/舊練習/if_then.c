#include <stdio.h>


int main(void){

    int apple;
    int egg;
    scanf("%d", &egg);
    if (egg >= 1)
        apple = 6;
    else
        apple = 1;
    printf("%d\n", apple);

    return 0;
}