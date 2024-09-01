/**
 * @file get_lsb.cpp
 * @author your name (you@domain.com)
 * @brief  這題是要求你實作一個函數，這個函數會找出一個數字的最低位元的1的位置
 * @version 0.1
 * @date 2024-09-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "bits/stdc++.h"

using namespace std;

int main(void){
    int n;
    cin >> n;

    bitset<32> b(n);
    bitset<32> b_lsb(n & -n);
    cout << b << endl;
    cout << b_lsb << endl;
}