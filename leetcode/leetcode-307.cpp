/*
 *@File Name          :leetcode-307.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/7 8:50
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class NumArray {

private:
    vector<int> a, nums;
    int n;
public:

    inline int lowbit(int x) {
        return x & -x;
    }

    void add(int x, int v) {
        while (x <= n) {
            a[x] += v;
            x += lowbit(x);
        }
    }

    int getSum(int x) {
        int ans = 0;
        while (x >= 1) {
            ans += a[x];
            x -= lowbit(x);
        }
        return ans;
    }

    int query(int x, int y) {
        return getSum(y) - getSum(x - 1);
    }

    NumArray(vector<int> &nums) : nums(nums) {
        n = nums.size();
        a = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++)
            add(i + 1, nums[i]);
    }

    void update(int index, int val) {
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        return query(left + 1, right + 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */