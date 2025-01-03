#include <stdio.h>


int main(void){
    
    int sum = 0;
    int i, n;
    scanf ("%d", &n);
    for (i = 0; i <= n; i++)
        sum += i;
    printf("%d\n", sum);

    return 0;
}