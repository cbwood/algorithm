#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[10001];
        memset(dp,0x5f, sizeof(dp));
        dp[0] = 0;
        int n = coins.size();
        for(int j = 0; j < n; j++)
            for(int i = coins[j]; i <= amount; i++)
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
        return dp[amount] == 1600085855? -1: dp[amount];
    }
};

int main(){
    Solution so;
    vector<int> a{1, 2, 5};
    printf("%d\n", so.coinChange(a, 11));
    return 0;
}