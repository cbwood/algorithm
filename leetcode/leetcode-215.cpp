/*
 * @File Name          :leetcode-215.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/2 14:56
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        for(auto &x: nums){
            que.push(x);
            while (que.size()> k)
                que.pop();
        }return que.top();

    }
};