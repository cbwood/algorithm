//
// Created by cb on 2021/12/20.
//

#include "algorithm"
#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> dp(k+1, 1);
        int k1=1,k2=1,k3=1;
        for(int i = 2; i <= k; i++){
            dp[i] = min(dp[k1]*3, min(dp[k2]*5, dp[k3]*7));
            if(dp[i] == dp[k1]*3) k1++;
            if(dp[i] == dp[k2]*5) k2++;
            if(dp[i] == dp[k3]*7) k3++;
        }
        return dp[k];
    }
};

int main(){
    Solution so;
    cout<<so.getKthMagicNumber(5)<<endl;
    return 0;
}