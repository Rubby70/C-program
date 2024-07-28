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

int main(void){

    car AAA[3];
    strcpy((AAA[0]).brand, "BMW");
    strcpy((AAA[1]).brand, "BENZ");
    strcpy((AAA[2]).brand, "AUDI");
    for(int i = 0; i < 3; i ++){
        printf("品牌: %s\n", (AAA[i]).brand);
    }
    return 0;

}