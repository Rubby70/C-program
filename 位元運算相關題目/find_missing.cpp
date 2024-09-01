/**
 * @file find_duplicate_and_missing.cpp
 * @author your name (you@domain.com)
 * @brief  這題利用XOR的特性來找重複的數字和缺少的數字，首先我們將所有的數字和1到n做XOR，
 *         由於XOR的特性，重複的數字會變成0，所以整題只會有缺少的那個數字只做到一次XOR，
 *         重複的數字會做兩次XOR，所以最後的結果就會是缺少的數字。
 * @version 0.1
 * @date 2024-09-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "bits/stdc++.h"


using namespace std;


int main(void){
    vector<int> arr = {1,2,5,4};
    int check = 0;

    for(int i = 0; i <= arr.size(); i ++){
        check ^= (i + 1);
    }

    for(int i = 0; i < arr.size(); i ++){
        check ^= arr[i];
    }

    cout << check << endl;
    return 0;
}