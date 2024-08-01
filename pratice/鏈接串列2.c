#include <stdio.h>
#include <string.h>


struct CAR{

    char brandname[10];
    char model[10];
    int productionyear;

};
typedef struct CAR car;

struct NODE{

    car testlist;
    struct NODE *ptr2node;

};
typedef struct NODE node;

int main(void){

    char name[5][10] = {"A", "B", "C", "D", "E"};
    node linkedlist[5];
    node *ptr2node_main = &linkedlist[0];
    for(int i = 0; i < 5; i ++){
        strcpy(ptr2node_main->testlist.brandname, name[i]);
        printf("%d, %s, \n", i, ptr2node_main->testlist.brandname);
        if(i == (5 - 1)){
            ptr2node_main->ptr2node = 0;
        }
        else{
            ptr2node_main->ptr2node = &linkedlist[i + 1];
        }
        ptr2node_main = ptr2node_main->ptr2node;
    }

    printf("--------------------\n");
    for(int i = 0; i < 5; i ++){
        printf("%d, %s, \n", i, linkedlist[i].testlist.brandname);
        //printf("%10p\n", linkedlist[i]);
    }
    return 0;

}