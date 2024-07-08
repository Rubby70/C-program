#include <stdio.h>


void PrintMatrix(char []);

int main(void){

    char A[] = "Hello world";
    char B[] = {'H','e','l','l','o',' ','w','o','r','l','d','\0'};

    printf("\n");
    PrintMatrix(A);
    PrintMatrix(B);

    printf("%s\n", A);

    return 0;
    
}

void PrintMatrix(char Arr[]){

    for(int i = 0; Arr[i] != '\0'; i ++){
        printf("%c", Arr[i]);
    }
    printf("\n");

}