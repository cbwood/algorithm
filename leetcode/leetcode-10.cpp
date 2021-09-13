#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length(),n=p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i = 0; i < n; ++i)
            if(p[i] == '*')
                dp[0][i+1] = dp[0][i-1];
        for(int i = 0; i < m; ++i)
            for(int j = 0;j < n; ++j){
                if(s[i] == p[j] || p[j] == '.')
                    dp[i+1][j+1] = dp[i][j];
                else if(p[j] == '*'){
                    if(s[i] == p[j-1] || p[j-1] == '.')
                        dp[i+1][j+1] = dp[i+1][j-1] || dp[i+1][j-1]||dp[i][j+1];
                    else dp[i+1][j+1] = dp[i+1][j-1];
                }
            }
        return dp[m][n];
    }
};

int main(){
    string s,p;
    cin >> s >> p;
    Solution so;
    cout << so.isMatch(s,p)<<endl;
}