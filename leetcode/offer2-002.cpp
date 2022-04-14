/*
 *@File Name          :offer2-002.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/13 20:29
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.size();
        int len_b = b.size();
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        string ans = "";
        int k = 0, carry = 0;
        while (k < len_a || k < len_b) {
            int num_a = 0, num_b = 0;
            if (k < len_a)
                num_a = a[k] - '0';
            if (k < len_b)
                num_b = b[k] - '0';
            k++;
            ans += to_string((num_a + num_b + carry) % 2);
            carry = (num_a + num_b + carry) / 2;
        }
        if (carry) {
            ans += to_string(carry);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};