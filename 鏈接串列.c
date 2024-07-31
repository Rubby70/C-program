#include <stdio.h>
#include <string.h>


struct CAR{

    char brandname[10];

};
typedef struct CAR car;

struct NODE{

    car data;
    struct NODE *next;

};
typedef struct NODE node;

void put2node(node *ptr, char brand[][10]){

    int i = 0;
    while(ptr != 0){
        strcpy(ptr->data.brandname, brand[i]);
        i ++;
        ptr = ptr->next;
    }
    
}

void printnode(node *ptr){

    while(ptr != 0){
        printf("%s \n",ptr->data.brandname);
        ptr = ptr->next;
    }

}

int main(void){

    char brand[3][10] = {"AA", "BB", "CC"};
    node A,B,C;
    A.next = &B;
    A.next->next = &C;
    A.next->next->next = 0;
    // strcpy(A.data.brandname, "AA");
    // strcpy(B.data.brandname, "BB");
    // strcpy(A.next->next->data.brandname, "CC");

    node *ptr = &A;
    put2node(ptr, brand);
    printnode(ptr);
    return 0;

}