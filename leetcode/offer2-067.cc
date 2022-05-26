/*
 *@File Name          :offer2-067.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/26 9:52
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "set"

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        int ans = 0;
        set<int> se;
        for (int i = 30; i >= 0; --i) {
            se.clear();
            for (auto &num: nums)
                se.insert(num >> i);
            int nans = ans * 2 + 1;
            bool flag = false;
            for (auto &num: nums) {
                if (se.count((num >> i) ^ nans)) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                ans = nans;
            else ans = nans - 1;
        }
        return ans;
    }
};