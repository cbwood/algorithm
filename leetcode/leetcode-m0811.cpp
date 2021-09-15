//
// Created by cb on 2021/9/15.
//

#include "iostream"
#include "vector"

using namespace std;


class Solution {
public:
    int waysToChange(int n) {
        int mod = 1e9 + 7;
        vector<int> dp(n + 2, 0);
        int w[4] = {1, 5, 10, 25};
        dp[0] = 1;
        for(int v: w)
            for(int i = v; i <= n; i++)
                dp[i] = (dp[i]+dp[i-v])%mod;
        return dp[n];
    }
};

int main() {
    Solution so;
    cout << so.waysToChange(5);
    return 0;
}
