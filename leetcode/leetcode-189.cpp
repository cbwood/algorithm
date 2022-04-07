/*
 *@File Name          :leetcode-189.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/1 18:23
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;


class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        k = k % nums.size();
        std::reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


class Solution1 {
public:

    inline int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k = k % n;
        int m = gcd(n, k);
        for (int i = 0; i < m; i++) {
            int cur = i;
            int x = nums[i];
            do {
                cur = (cur + k) % n;
                swap(nums[cur], x);
            } while (cur != i);
        }
    }
};