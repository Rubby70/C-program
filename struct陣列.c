#include <stdio.h>
#include <string.h>


struct Car{
    char number[10];
    char driver[10];
    char brand[20];
    char carModel[20];
    int yearOfProduction;
    int engineDisplacement;
    double fuelConsumption;
};
typedef struct Car car;

void print1(car BBB){

    printf("BBB.brand: %s\n", BBB.brand);

}

void print2(car *ptr){

    printf("(*ptr).brand: %s\n", ptr->brand);

}

void putnameintostruct(car *ptr2car,char brandname[][10], int count){

    for(int i = 0; i < count; i ++){
        strcpy(ptr2car[i].brand, brandname[i]);
    }

}

void printcarbrand(car *ptr2car, int count){

    for(int i = 0; i < count; i ++){
        printf("品牌名稱: (%d) %s\n", i, ptr2car[i].brand);
    }

}

int main(void){

    printf("Part 1\n");
    car ABC;
    strcpy(ABC.brand, "VOLVO");
    car *ptr1, *ptr2;
    ptr1 = &ABC;
    ptr2 = ptr1;
    printf("ABC.brand: %s\n", ABC.brand);
    printf("(*ptr1).brand: %s\n", (*ptr1).brand);
    printf("ptr2->brand: %s\n", ptr2->brand);
    print1(ABC);
    print2(&ABC);

    printf("Part 2\n");
    car AAA[3];
    strcpy((AAA[0]).brand, "BMW");
    strcpy((AAA[1]).brand, "BENZ");
    strcpy((AAA[2]).brand, "AUDI");
    for(int i = 0; i < 3; i ++){
        printf("品牌: %s\n", (AAA[i]).brand);
    }

    printf("Part 3\n");
    car TEST[5];
    char brandname[3][10] = {"NISSAN", "TOYOTA", "HONDA"};
    putnameintostruct(TEST, brandname, 3);
    printcarbrand(TEST, 3);
    return 0;

}