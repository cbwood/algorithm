/*
 *@File Name          :offer2-076.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/6 8:24
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "queue"
#include "vector"
using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, deque<int>, greater<int>> que;
    for (auto& x : nums) {
      que.push(x);
      if (que.size() > k) que.pop();
    }
    int ans = que.top();
    return ans;
  }
};