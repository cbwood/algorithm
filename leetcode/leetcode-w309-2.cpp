#include <bits/stdc++.h>
using namespace std;

const long long           mod = 1e9 + 7;


class Solution {
 public:
 
  vector<vector<long long>> dp;
  long long dfs(int cur, int k, int endPos) {
    if (dp[cur][k] != -1) return dp[cur][k];
    long long ans = 0;
    if (cur == endPos && k == 0) return 1;
    if (k == 0) return 0;
    ans = (dfs(cur - 1, k - 1, endPos) + dfs(cur + 1, k - 1, endPos)) % mod;
    dp[cur][k] = ans;
    return ans;
  }

  int numberOfWays(int startPos, int endPos, int k) {
    dp.resize(3001, vector<long long>(3001, -1));
    if ((k - endPos + startPos) & 1) return 0;
    return dfs(startPos + 1000, k, endPos + 1000)%mod;
  }
};