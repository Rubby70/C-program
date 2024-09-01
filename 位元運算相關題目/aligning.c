/**
 * @file aligning.c
 * @author your name (you@domain.com)
 * @brief  這題是要求你實作兩個函數，一個是flooring，一個是ceiling，
 *         flooring是找出比target小的最大的2的次方數，
 *         ceiling是找出比target大的最小的2的次方數。
 *         例如flooring(5) = 4, ceiling(5) = 8。
 *         這題只能用在32位元的整數上，所以不用考慮超過32位元的情況。
 * @version 0.1
 * @date 2024-09-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "stdio.h"
#include "stdlib.h"

int ceiling(int target) { 
    target |= (target >> 1);
    target |= (target >> 2);
    target |= (target >> 4);
    target |= (target >> 8);
    target |= (target >> 16);
    return target + 1;
}


int flooring(int target){
    int mask = 0;
    target |= (target >> 1);
    target |= (target >> 2);
    target |= (target >> 4);
    target |= (target >> 8);
    target |= (target >> 16);
    return  target - (target >> 1);

}

int main(void) {
  int a;
  scanf("%d", &a);
  printf("flooring(%d) = %d\n",a ,flooring(a));
  printf("ceiling(%d) = %d\n",a ,ceiling(a));
  return 0;
}
