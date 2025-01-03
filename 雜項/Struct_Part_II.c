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

    car AAA1234;
    strcpy(AAA1234.number, "AAA-1234");
    strcpy(AAA1234.driver, "seal");
    strcpy(AAA1234.brand, "Benz");
    strcpy(AAA1234.carModel, "S500");
    AAA1234.yearOfProduction = 2024;
    AAA1234.engineDisplacement = 2000;
    AAA1234.fuelConsumption = 20.5;
    printf("\nstruct Car AAA1234\n");
    printf("車牌號碼: %s\n", AAA1234.number);
    printf("駕駛人: %s\n", AAA1234.driver);
    printf("廠牌: %s\n", AAA1234.brand);
    printf("車型: %s\n", AAA1234.carModel);
    printf("出廠年份: %d\n", AAA1234.yearOfProduction);
    printf("排氣量: %d cc\n", AAA1234.engineDisplacement);
    printf("油耗: %5.2f km/L\n", AAA1234.fuelConsumption);

    car *ptr = &AAA1234;
    car *ptr123 = ptr;
    printf("\n");
    printf("用指標取品牌: %s\n", (*ptr).brand);
    printf("用指標取車牌: %s\n", ptr->number);
    printf("用指標取車主: %s\n", ptr123->driver);
    printf("\n");
    return 0;
    
}