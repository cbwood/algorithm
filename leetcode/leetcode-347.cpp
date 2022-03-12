/*
 *@File Name          :leetcode-347.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/11 14:30
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "map"
#include "unordered_map"
#include "ctime"

using namespace std;

class Solution {
public:
    vector<int> ans;

    void sortma(vector<pair<int, int>> &vec, int l, int r, int k) {
        if (l > r) return;
        int t = rand() % (r - l + 1) + l;
        swap(vec[t], vec[l]);
        int lx = l;
        int rx = r;
        while (lx < rx) {
            while (lx < rx && vec[rx].second <= vec[l].second) rx--;
            while (lx < rx && vec[lx].second >= vec[l].second) lx++;
            if (lx < rx) swap(vec[lx], vec[rx]);
        }
        swap(vec[lx], vec[l]);
        if (lx - l + 1 > k) {
            sortma(vec, l, lx - 1, k);
        } else {
            for (int i = l; i <= lx; i++)
                ans.emplace_back(vec[i].first);
            if (lx - l + 1 < k) {
                sortma(vec, lx + 1, r, k - (lx - l + 1));
            }
        }
    }

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> ma;
        for (auto &x: nums)
            ma[x]++;
        vector<pair<int, int>> vec(ma.size());
        for (auto &x: ma) {
            vec.emplace_back(x);
        }
        srand((unsigned) time(nullptr));
        sortma(vec, 0, vec.size() - 1, k);
        return ans;
    }
};