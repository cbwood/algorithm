//
// Created by cb on 2021/12/20.
//

#include "algorithm"
#include "vector"
#include "string"
#include "map"
using namespace std;

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.size();
        vector<int>dp(n+1, 0);
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i-1] + 1;
            for(auto &x: dictionary){
                if(i >= x.size() && sentence.substr(i-x.size(),x.size()) == x){
                    dp[i] = min(dp[i], dp[i-x.size()]);
                }
            }
        }return dp[n];
    }
};