#include <stdio.h>


int main(void){

    int i;
    int a[10];
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < 10; i++)
        printf("%d\n", a[i]);

    return 0;

}