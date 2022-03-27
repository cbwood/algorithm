/*
 *@File Name          :leetcode-682.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/26 8:39
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "string"
#include "stack"

using namespace std;


class Solution {
public:
    int calPoints(vector<string> &ops) {
        stack<int> que;
        for (auto &x: ops) {
            if (x == "C") {
                que.pop();
            } else if (x == "D") {
                que.push(que.top() * 2);
            } else if (x == "+") {
                int a = que.top();
                que.pop();
                int b = que.top() + a;
                que.push(a);
                que.push(b);
            } else {
                que.push(stoi(x));
            }
        }
        int ans = 0;
        while (!que.empty()) {
            ans += que.top();
            que.pop();
        }
        return ans;
    }
};