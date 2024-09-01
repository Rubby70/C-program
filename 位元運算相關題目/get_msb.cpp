/**
 * @file get_msb.cpp
 * @author your name (you@domain.com)
 * @brief  這題是要求你實作一個函數，這個函數會找出一個數字的最高位元的1的位置
 * @version 0.1
 * @date 2024-09-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "bits/stdc++.h"

using namespace std;

int ceiling(int n){
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);
    return n + 1;
}

int get_msb(int n){
    return ceiling(n) >> 1;
}

int main(void){
    int n = 1024;
    // cin >> n;

    bitset<32> b(n);
    cout << b << endl;
    cout << bitset<32>(ceiling(n)) << endl;
    cout << bitset<32>(get_msb(n)) << endl;
}