/*
 *@File Name          :leetcode-852.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/10 21:12
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1])
                return i - 1;
        }
        return 0;
    }
};