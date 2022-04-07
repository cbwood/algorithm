/*
 *@File Name          :leetcode-728.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/31 9:03
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        auto natrueDived = [](int x) -> bool {
            int t = x;
            while (x) {
                if (x % 10 == 0 || t % (x % 10)) return false;
                x /= 10;
            }
            return true;
        };
        for (int i = left; i <= right; i++) {
            if (natrueDived(i))
                ans.emplace_back(i);
        }
        return ans;
    }
};