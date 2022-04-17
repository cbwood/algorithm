/*
 *@File Name          :leetcode-w289-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/17 10:27
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "string"
#include "map"

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int> &tasks) {
        std::sort(tasks.begin(), tasks.end());
        int ans = 0;
        int num = 1;
        int prex = tasks[0];
        int n = tasks.size();
        for (int i = 1; i < n; i++) {
            if (tasks[i] != tasks[i - 1]) {
                if (num == 1) return -1;
                if (num % 3 == 0) {
                    ans += num / 3;
                } else {
                    ans += num / 3 + 1;
                }
                num = 0;
            }
            num++;
        }
        if (num == 1) return -1;
        if (num % 3 == 0) {
            ans += num / 3;
        } else {
            ans += num / 3 + 1;
        }
        return ans;
    }
};