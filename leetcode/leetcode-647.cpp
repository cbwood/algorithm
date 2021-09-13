#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; ++i){
            if(i<n-1&&s[i]==s[i+1])
                dp[i][i+1] = 1;
            dp[i][i] = 1;
        }
        for(int i = n-3; i >= 0; --i)
            for(int j = i+2; j < n; ++j){
                if(s[i] == s[j])
                    dp[i][j] = dp[i][j]|dp[i+1][j-1];
            }
        int ans = 0;
        // for(int i = 0; i < n; ++i){
        //     for(int j = 0; j < n-1; ++j)
        //         printf("%d ", dp[i][j]);
        //     printf("%d\n", dp[i][n-1]);
        // }
        for(int i = 0; i < n; ++i)
            for(int j = i; j < n; ++j)
                if(dp[i][j]) ans++;
        return ans;
    }
};

int main(){
    Solution so;
    cout << so.countSubstrings("dnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvg")<< endl;
    return 0;
}

//"dnncbwoneinoplypwgbwktmvkoimcooyiwirgbxlcttgteqthcvyoueyftiwgwwxvxvg"