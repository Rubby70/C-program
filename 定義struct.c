#include <stdio.h>
#include <string.h>


typedef struct{
    char flight_number[10];
    char airline[30];
    char origin[10];
    char destination[10];
    int frequency, sitCapacity;
    double duration;
} Flight;

struct car{
    char number[10];
    char driver[10];
    char brand[20];
    char carModel[20];
    int yearOfProduction;
    int engineDisplacement;
    double fuelConsumption;
};
typedef struct car Car;



int main(void){

    Flight EK367;
    printf("struct Flight EK367\n");
    printf("flight_number: %s\n", EK367.flight_number);
    printf("airline: %s\n", EK367.airline);
    printf("origin -> destination: %s -> %s\n", EK367.origin, EK367.destination);
    printf("frequency: %d\n", EK367.frequency);
    printf("sitCapacity: %d\n", EK367.sitCapacity);
    printf("duration: %f\n", EK367.duration);

    Car ABC123;
    strcpy(ABC123.number, "QQQ-9999");
    strcpy(ABC123.driver, "seal");
    strcpy(ABC123.brand, "Benz");
    strcpy(ABC123.carModel, "S500");
    ABC123.yearOfProduction = 2024;
    ABC123.engineDisplacement = 2000;
    ABC123.fuelConsumption = 20.5;
    printf("\nstruct Car ABC123\n");
    printf("車牌號碼: %s\n", ABC123.number);
    printf("駕駛人: %s\n", ABC123.driver);
    printf("廠牌: %s\n", ABC123.brand);
    printf("車型: %s\n", ABC123.carModel);
    printf("出廠年份: %d\n", ABC123.yearOfProduction);
    printf("排氣量: %d cc\n", ABC123.engineDisplacement);
    printf("油耗: %5.2f km/L\n", ABC123.fuelConsumption);

    Car AAA111;
    AAA111 = ABC123;
    strcpy(AAA111.number, "AAA-1111");
    printf("\nstruct Car AAA111\n");
    printf("車牌號碼: %s\n", AAA111.number);
    printf("駕駛人: %s\n", AAA111.driver);
    printf("廠牌: %s\n", AAA111.brand);
    printf("車型: %s\n", AAA111.carModel);
    printf("出廠年份: %d\n", AAA111.yearOfProduction);
    printf("排氣量: %d cc\n", AAA111.engineDisplacement);
    printf("油耗: %5.2f km/L\n", AAA111.fuelConsumption);

    Car BBB222 = {"BBB-2222", "sss", "BMW", "420i", 1, 1, 2.2};
    printf("\nstruct Car BBB222\n");
    printf("車牌號碼: %s\n", BBB222.number);
    printf("駕駛人: %s\n", BBB222.driver);
    printf("廠牌: %s\n", BBB222.brand);
    printf("車型: %s\n", BBB222.carModel);
    printf("出廠年份: %d\n", BBB222.yearOfProduction);
    printf("排氣量: %d cc\n", BBB222.engineDisplacement);
    printf("油耗: %5.2f km/L\n", BBB222.fuelConsumption);
    return 0;

}