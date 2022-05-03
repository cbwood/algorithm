/*
 *@File Name          :offer2-037.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/3 9:10
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "deque"

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vector<int> ans;
        deque<int> que;
        for (auto &x: asteroids) {
            if (x > 0) que.push_back(x);
            else {
                while (!que.empty() && -x >= que.back()) {
                    if (-x == que.back()) {
                        que.pop_back();
                        x = 0;
                        break;
                    } else que.pop_back();
                }
                if (x != 0 && que.empty())
                    ans.push_back(x);
            }
        }
        while (!que.empty()) {
            ans.push_back(que.front());
            que.pop_front();
        }
        return ans;
    }
};