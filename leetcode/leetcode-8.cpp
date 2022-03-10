/*
 *@File Name          :leetcode-8.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/10 9:04
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int flag = 1;
        bool check = false;
        for (auto &x: s) {
            if (x == ' ' && !check)
                continue;
            if (check && (x < '0' || x > '9'))
                break;
            if (x == '-') {
                flag = -1;
                check = true;
            } else if (x == '+') {
                flag = 1;
                check = true;
            } else if (x >= '0' && x <= '9') {
                ans = ans * 10 + x - '0';
                if (ans > 1LL + INT_MAX) {
                    if (flag == 1)
                        return INT_MAX;
                    return INT_MIN;
                };
                check = true;
            } else break;
        }
        ans = ans * flag;
        if (ans <= INT_MIN) return INT_MIN;
        if (ans >= INT_MAX) return INT_MAX;
        return ans;
    }
};