#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> ans;
        double dp[12][7]={0};
        for(int i = 1; i <= 6; i++)
            dp[0][i] = 1.0/6;
        int k = 1;
        for(int i = 2; i < n; i++){
            k *= 6;
            for(int j = 1; j <= k; j++)
                for(int q = 1; q <= 6; q++)
                    dp[i][j+q] += dp[i-1][j]/6;
        }for(int i = 1; i <= k*6; i++)
            ans.push_back(dp[n-1][i]);
        return ans;
    }
};

int main (){
    return 0;
}