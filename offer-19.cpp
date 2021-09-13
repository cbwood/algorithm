#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        auto match = [&](int i, int j){
            if(i == 0) return false;
            if(p[j-1] == '.') return true;
            return s[i-1] == p[j-1];
        };
        dp[0][0] = true;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j){
                if(p[j-1] == '*'){
                    dp[i][j] |= dp[i][j-2];
                    if(match(i, j-1))
                        dp[i][j] |= dp[i-1][j];
                }else if(match(i,j))
                        dp[i][j] |= dp[i-1][j-1];
            }return dp[n][m];
    }
};

int main(){

    return 0;
}