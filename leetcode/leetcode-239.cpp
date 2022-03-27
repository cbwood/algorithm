/*
 *@File Name          :leetcode-239.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/27 9:29
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> dq;
        int n = nums.size();
        for (int i = 0; i < min(k, n); i++) {
            while (!dq.empty() && dq.back() < nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
        }
        vector<int> ans;
        ans.push_back(dq.front());
        for (int i = k; i < n; i++) {
            while (!dq.empty() && dq.back() < nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
            if (dq.front() == nums[i - k])
                dq.pop_front();
            ans.push_back(dq.front());
        }
        return ans;
    }
};

class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        map<int, int> ma;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ma[nums[i]]++;
        }
        ans.emplace_back(ma.rbegin()->first);
        for (int i = k; i < nums.size(); i++) {
            ma[nums[i]]++;
            ma[nums[i - k]]--;
            if (ma[nums[i - k]] == 0)
                ma.erase(nums[i - k]);
            ans.emplace_back(ma.rbegin()->first);
        }
        return ans;
    }
};