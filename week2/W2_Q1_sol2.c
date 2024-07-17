#include <stdio.h>
#include "math.h"


int main(void) {
    
    int target;
    scanf("%d", &target);
    printf("The input number is: %d.\n", target);

    int proc_num = target;
    int multiplier = 1; // 用來追蹤當前位數的乘數
    int ret_val = target;
    int pos = 0;
    int highest_six_pos = -1;
    
    while (proc_num) {
        if (proc_num % 10 == 6) {
            highest_six_pos = pos;
        }
        proc_num /= 10;
        pos++;
    }

    if (highest_six_pos != -1) {
        ret_val = target + 3 * (int)pow(10, highest_six_pos); // 將最左邊的6變成9，差值為3
    }
    
    printf("The result is: %d.\n", ret_val);
    return 0;
}
