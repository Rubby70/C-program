#include "stdio.h"
#include "stdlib.h"
#include "math.h"


int main(void){

    int target;
    scanf("%d", &target);
    printf("The input number is: %d.\n", target);
    int check = target;
    int digit_num = 0;
    while(check){
        check /= 10;
        digit_num += 1;
    }
    printf("The number of digit is: %d.\n", digit_num);

    int proc_num = target;
    int MSD_6 = 0;
    for(int proc_digit = 0; proc_digit < digit_num; proc_digit ++, proc_num /= 10){
        if(proc_num % 10 == 6){
            printf("Update MSD_6.\n");
            MSD_6 = proc_digit + 1;
        }
    }
    int ret_val = target;
    if(MSD_6){
        printf("The MSD_6 is: %d.\n", MSD_6);
        ret_val = target - (6 * (int)pow(10, MSD_6 - 1)) + (9 * (int)pow(10, MSD_6 - 1));
    }
    printf("The result is: %d.\n", ret_val);
    return 0;

}