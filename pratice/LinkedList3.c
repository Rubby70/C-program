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
        strcpy(ptr->carlist.brandname, carname[i]);
        if(i == (count - 1)){
            ptr[i].ptr2node = 0;
        }
        else{
            ptr[i].ptr2node = &ptr[i + 1];
        }
        strcpy(ptr->carlist.brandname, carname[i]);
        printf("%d, %s\n", i, ptr->carlist.brandname);
    }
    *ptr2LL_main = &ptr[0];

}

int main(void){

    char carname[5][10] = {"A", "B", "C", "D", "E"};
    node linkedlist[5];
    node *ptr2LL_main = NULL;
    buildLL_2(&ptr2LL_main, linkedlist, carname, 5);

    //add
    char target[5] = "C";
    node additionallist;
    int count = 0;
    // while(ptr2LL_main != NULL){
    //     if(ptr2LL_main->carlist.brandname == target){
    //         printf("found: %d\n", count);
    //         node *temp = ptr2LL_main->ptr2node;
    //         ptr2LL_main->ptr2node = &additionallist;
    //         additionallist.ptr2node = temp;
    //         break;
    //     }
    //     ptr2LL_main = ptr2LL_main->ptr2node;
    //     count ++;
    // }
    while(ptr2LL_main != NULL){
        printf("%s\n", ptr2LL_main->carlist.brandname);
        ptr2LL_main = ptr2LL_main->ptr2node;
    }
    return 0;

}