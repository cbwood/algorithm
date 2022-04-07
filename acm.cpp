#include "bits/stdc++.h"

using namespace std;
class Solution {
private:
    static constexpr int mod = 1000000007;
    static constexpr int coins[3] = {3, 2, 1};

public:
    int waysToChange(int n) {
        vector<int> f(n + 1);
        f[0] = 1;
        for (int c = 0; c < 3; ++c) {
            int coin = coins[c];
            for (int i = coin; i <= n; ++i) {
                f[i] = (f[i] + f[i - coin]) % mod;
            }
        }
        return f[n];
    }
};


int main() {
    Solution so;
    cout << so.waysToChange(20) << endl;
    return 0;
}