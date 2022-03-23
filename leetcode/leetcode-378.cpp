/*
 *@File Name          :leetcode-378.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/21 16:51
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "queue"

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> que;
        for (int i = 0; i < n; i++)
            que.push({matrix[i][0], i, 0});
        for (int i = 0; i < k - 1; i++) {
            vector<int> p = que.top();
            que.pop();
            if (p[2] != n - 1) {
                que.push({matrix[p[1]][p[2] + 1], p[1], p[2] + 1});
            }
        }
        return que.top()[0];
    }
};