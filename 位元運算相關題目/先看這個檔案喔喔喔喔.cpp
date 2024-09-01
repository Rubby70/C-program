/**
 * @file 先看這個檔案喔喔喔喔.cpp
 * @author your name (you@domain.com)
 * @brief  這個程式是要求你將輸入的數字轉換成二進位數字，並且印出來，算是一個可以輕鬆可視化二進位數字的程式
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

    bitset<32> bs(n);
    cout << bs << endl;

}