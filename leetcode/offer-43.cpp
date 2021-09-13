#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int a[31];
    int dp[31][11];
    int dfs(int pos, bool limit, int sum){
        if(pos == -1) return sum;
        if(!limit&&dp[pos][sum] != -1) return dp[pos][sum];
        int up = limit ? a[pos] : 9;
        int ans = 0;
        for(int i = 0; i <= up; ++i){
            ans += dfs(pos-1, limit&&i==a[pos], sum+(i == 1));
        }if(!limit) dp[pos][sum] = ans;
        return ans;
    }
    int countDigitOne(int n) {
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        int num = 0;
        while(n){
            a[num++] = n%10;
            n /= 10;
        }
        ans = dfs(num-1, true, 0);
        return ans;
    }
};

int main(){
    Solution so = Solution();
    cout<<so.countDigitOne(999)<<endl;
    return 0;
}