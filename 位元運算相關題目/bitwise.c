/**
 * @file bitwise.c
 * @author your name (you@domain.com)
 * @brief 這題是要求你實作四個函數，分別是setbit, clearbit, togglebit, checkBit，
 *        setbit是將target的第whichBit設為1，
 *        clearbit是將target的第whichBit設為0，
 *        togglebit是將target的第whichBit取反，
 *        checkBit是檢查target的第whichBit是否為1。
 * @version 0.1
 * @date 2024-09-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "stdio.h"
#include "stdbool.h"

void setbit(int target, int whichBit);
void clearbit(int target, int whichBit);
void togglebit(int target, int whichBit);
bool checkBit(int target, int whichBit);

int main(void) {}


void setbit(int target, int whichBit) {
    int tool = 1 << whichBit;
    target |= tool;
}

void clearbit(int target, int whichBit) {
    int tool = 1 << whichBit;
    target &= (~tool);
}

void togglebit(int target, int whichBit) {
    int tool = 1 << whichBit;
    target ^= tool;
}


bool checkBit(int target, int whichBit) {
    int tool = 1 << whichBit;
    return target & tool;
}


int highestBit(int target) {
    int num = target;
    target |= target >> 1;
    target |= target >> 2;
    target |= target >> 4;
    target |= target >> 8;
    target |= target >> 16;
    return target - (target >> 1);
    // for a 32bit int using this method to fill all of the bit which is less
    // significant than the highest 1
    // using minus to get rid of them all
}
