/*
*@File Name          :leetcode-504.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/3/7 9:07
*@Description        :
*@Function List      :
*@History            :
*/

#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        int x = 0;
        string t = "";
        if (num < 0) {
            t = "-";
            num = -num;
        }
        while (num) {
            ans = to_string(num % 7) + ans;
            num /= 7;
        }
        if (ans == "") ans = "0";
        ans = t + ans;
        return ans;
    }
};