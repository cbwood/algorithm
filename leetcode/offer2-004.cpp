/*
 *@File Name          :offer2-004.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/13 21:05
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "bitset"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int num_zero = 0;
            for (const auto &x: nums) {
                if (x & (1 << i))
                    ++num_zero;
            }
            if (num_zero % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};