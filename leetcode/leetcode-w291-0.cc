/*
 *@File Name          :leetcode-w291-0.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/1 10:21
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        int k = 0;
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == digit) {
                k = i;
                if (i < number.size() - 1 && number[i] < number[i + 1]) {
                    return number.substr(0, i) + number.substr(i + 1, number.size() - (i + 1));
                }
            }
        }
        if (k == number.size())
            return number.substr(0, number.size() - 1);
        return number.substr(0, k) + number.substr(k + 1, number.size() - (k + 1));
    }
};