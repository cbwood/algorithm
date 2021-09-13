#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3+10;
int dp[maxn][maxn];

int main(){
    string s;
    getline(cin, s);
    int len = s.length();
    int ans = 1;
    for(int i = 0; i < len; ++i){
        dp[i][i] = 1;
        if(i<len-1 && s[i] == s[i+1])
            dp[i][i+1]=2,ans=2;
    }
    for(int i = len-2; i >= 0; --i)
        for(int j = i+1; j < len;++j)
            if(dp[i+1][j-1]){
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                ans = max(ans, dp[i][j]);
            }
    cout << ans << endl;
}