#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        int  dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        int ans = 1;
        for(int i = n-1; i >= 0; i--)
            for(int j = i+1; j < n; j++)
                if(A[i] == A[j]&&(dp[i+1][j-1]||j==i+1)){
                        dp[i][j] = 1;
                        ans = max(ans, j-i+1);
                }
        return ans;
    }
};