#include <stdio.h>


void print(int (*B)[5]){

    for(int i = 0; i < sizeof(*B)/sizeof((*B)[0]); i ++){
        printf("%d ", (*B)[i]);
    }

}

int main(void){

    printf("\n");

    int A[] = {1, 2, 3, 4, 5};
    print(&A);

    printf("\n");
    return 0;

}