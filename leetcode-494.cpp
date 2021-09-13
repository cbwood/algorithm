#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long long sumx = 0;
        for (auto &x: nums)
            sumx += x;
        if((sumx+S)&1)
            return 0;
        if(S > sumx||S>1000)
            return 0;
        sumx = (sumx + S) / 2;
        int dp[sumx+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(auto &x: nums)
            for (int i = sumx; i >= x; --i)
                dp[i] += dp[i - x];
        return dp[sumx];
    }
};


int main(){
    Solution so;
    vector<int> q{1, 1, 1, 1, 1};
    printf("%d\n", so.findTargetSumWays(q, 3));
    return 0;
}