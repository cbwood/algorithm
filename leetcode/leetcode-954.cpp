/*
 *@File Name          :leetcode-954.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/1 9:46
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "list"
#include "map"

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        map<int, int> ma;
        list<int> li;
        std::sort(arr.begin(), arr.end());
        for (auto &x: arr) {
            ma[x]++;
            if (ma[x * 2] != 0) {
                ma[x * 2]--;
                ma[x]--;
            } else if (x % 2 == 0 && ma[x / 2] != 0) {
                ma[x / 2]--;
                ma[x]--;
            }
        }
        for (auto &x: ma) {
            if (x.second != 0) return false;
        }
        return true;
    }
};