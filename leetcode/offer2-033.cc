/*
 *@File Name          :offer2-033.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/30 9:14
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "algorithm"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> ans;
        map<string, int> ma;
        int k = 0;
        for (auto &x: strs) {
            string tmp = x;
            std::sort(x.begin(), x.end());
            if (ma.find(x) == ma.end()) {
                ma[x] = k++;
            }
            if (ans.size() <= ma[x]) {
                ans.emplace_back();
            }
            ans[ma[x]].push_back(tmp);
        }
        return ans;
    }
};