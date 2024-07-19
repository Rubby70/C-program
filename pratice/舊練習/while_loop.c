#include <stdio.h>


int main(void){

    int i = 1;
    int sum = 0;
    int n;
    scanf("%d", &n);
    while (i <= n){
        sum += i;
        i++;
    }
    printf("%d\n", sum);

    return 0;
}