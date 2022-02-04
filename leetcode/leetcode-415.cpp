/*
 * @File Name          :leetcode-415.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/2/4 15:11
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int x = 0;
        int n1 = num1.size() - 1, n2 = num2.size() - 1;
        while (n1 >= 0 && n2 >= 0) {
            int k = num1[n1] - '0' + num2[n2] - '0' + x;
            ans = string(1, k % 10 + '0') + ans;
            x = k / 10;
            n1--;
            n2--;
        }
        while (n1 >= 0) {
            int k = num1[n1] - '0' + x;
            ans = string(1, k % 10 + '0') + ans;
            x = k / 10;
            n1--;
        }
        while (n2 >= 0) {
            int k = num2[n2] - '0' + x;
            ans = string(1, k % 10 + '0') + ans;
            x = k / 10;
            n2--;
        }
        if (x) {
            ans = string(1, x + '0') + ans;
        }
        return ans;
    }
};