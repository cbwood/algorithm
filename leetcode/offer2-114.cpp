/*
 *@File Name          :offer2-114.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/6 9:20
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "map"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  string      ans;
  vector<int> c;

  bool dfs(vector<vector<bool>>& judge, int cur) {
    c[cur] = -1;
    for (int i = 0; i < 26; i++)
      if (i != cur && judge[cur][i]) {
        if (c[i] == -1) return false;
        if (c[i] == 0)
          if (!dfs(judge, i)) return false;
      }
    c[cur] = 1;
    ans.push_back(cur + 'a');
    return true;
  }

  string alienOrder(vector<string>& words) {
    vector<vector<bool>> judge(27, vector<bool>(27, false));
    int                  n = words.size();
    map<char, bool>      vis;
    c.resize(27, 0);
    for (int i = 0; i < n; i++) {
      int m = words[i].size();
      for (auto& x : words[i]) vis[x] = true;

      for (int j = i + 1; j < n; j++) {
        int  nn    = words[j].size();
        bool check = true;
        for (int k = 0; k < min(nn, m); k++) {
          if (words[i][k] != words[j][k]) {
            judge[words[i][k] - 'a'][words[j][k] - 'a'] = true;
            check                                       = false;
            break;
          }
        }
        if (check && nn < m) return "";
      }
    }
    for (auto& x : vis) {
      if (c[x.first - 'a'] == 0 && !dfs(judge, x.first - 'a')) return "";
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};