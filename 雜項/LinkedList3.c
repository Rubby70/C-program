#include <stdio.h>
#include <string.h>


struct CAR{

    char brandname[10];

};
typedef struct CAR car;

struct NODE{

    car carlist;
    struct NODE *ptr2node;

};
typedef struct NODE node;

void buildLL_2(node **ptr2LL_main, node *ptr, char carname[][10], int count){

    for(int i = 0; i < count; i ++){
        strcpy(ptr[i].carlist.brandname, carname[i]);
        if(i == (count - 1)){
            ptr[i].ptr2node = NULL;
        }
        else{
            ptr[i].ptr2node = &ptr[i + 1];
        }
        printf("i: %d, ptr: %p, string: %s\n", i, &ptr[i], ptr[i].carlist.brandname);
    }
    *ptr2LL_main = &ptr[0];

}

int main(void){

    char carname[5][10] = {"A", "B", "C", "D", "E"};
    node linkedlist[5];
    node *ptr2LL_main = NULL;
    buildLL_2(&ptr2LL_main, linkedlist, carname, 5);

    while(ptr2LL_main != NULL){
        printf("%s\n", ptr2LL_main->carlist.brandname);
        ptr2LL_main = ptr2LL_main->ptr2node;
    }
    return 0;

}