#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int a[503];
        int n = nums.size();
        a[0] = a[n+1] = 1;
        for(int i = 1; i <= n; ++i)
            a[i] = nums[i-1];
        int dp[503][503];
        n++;
        memset(dp, 0, sizeof(dp));
        for(int i = n-2; i >= 0; --i)
            for(int j = i+2; j <= n; ++j)
                for(int k = i+1; k < j; ++k){
                    int sum = a[i]*a[j]*a[k]+dp[i][k]+dp[k][j];
                    dp[i][j] = max(dp[i][j], sum);
                }
        return dp[0][n];

    }
};

int main(){
    Solution so;
    vector<int> a{3,1,5,8};
    printf("%d\n", so.maxCoins(a));
    return 0;
}