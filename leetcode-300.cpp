#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[1000];
        int k = 0, ans = min(1,n);
        for(int i = 0; i < n; ++i){
            int m = lower_bound(dp, dp+k, nums[i])-dp;
            printf("%d\n",m);
            dp[m] = nums[i];
            k = max(k, m+1);
            ans = max(ans, k);
        }return ans;
    }
};