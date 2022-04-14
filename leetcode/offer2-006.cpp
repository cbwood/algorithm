/*
 *@File Name          :offer2-006.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/13 21:31
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                return {l, r};
            } else if (numbers[l] + numbers[r] < target)
                l++;
            else r--;
        }
        return {l, r};
    }
};