#include <stdio.h>
#include <string.h>


struct Vehicle{

    char brand[10];
    char model[10];
    char owner[10];
    int productionyear;
    int enginedisplacement;
    double fuelconsumption;

};
typedef struct Vehicle vehicle; 

struct Transportation{

    int categories;
    vehicle car[2];
    vehicle bike;

};
typedef struct Transportation transportation;

void putintostruct(transportation *ptr2nested, char string2brandname[][10], int count){
    
    for(int i = 0; i < count; i ++){
        strcpy(ptr2nested->car[i].brand, string2brandname[i]);
    }

}

void putintostruct2(transportation *ptr2nested, char (*string2brandname[])[10], int count){
    
    for(int i = 0; i < count; i ++){
        strcpy(ptr2nested->car[i].brand, string2brandname[i]);
    }

}

void printfromstruct(transportation ptr2nested, int count){

    for(int i = 0; i < count; i ++){
        printf("%s\n", ptr2nested.car[i].brand);
    }

}

int main(void){

    printf("練習1\n");
    transportation test;
    test.categories = 2;
    strcpy(test.car[0].brand, "BENZ");
    strcpy(test.car[1].brand, "BMW");
    strcpy(test.bike.brand, "YAMAHA");
    printf("交通工具有%d種\n", test.categories);
    printf("汽車1的廠牌: %s\n", test.car[0].brand);
    printf("汽車2的廠牌: %s\n", test.car[1].brand);
    printf("摩托車的廠牌: %s\n", test.bike.brand);

    printf("練習2\n");
    transportation pratice;
    char brandname[2][10] = {"TOYOTA", "NISSAN"};
    putintostruct(&pratice, brandname, 2);
    printfromstruct(pratice, 2);

    printf("測試\n");
    char brandname2[2][10] = {"AAAAA", "BBBB"};
    putintostruct2(&pratice, brandname2, 2);
    printfromstruct(pratice, 2);
    return 0;

}