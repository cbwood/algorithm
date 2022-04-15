/*
 *@File Name          :ctrip-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/14 20:06
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

int main(){
    string s;
    cin >> s;
    int s_size = s.size();

    vector<vector<int>> dp(2, vector<int>(9, 0));
    const int mod = 1e9+7;
    dp[0][s[0]-'0']++;
    for(int i = 1; i < s_size; i++){
        dp[i&1] = dp[(i-1)&1];
        for(int j = 0; j < 9; j++){
            dp[i&1][(j+(s[i]-'0'))%9] += dp[(i-1)&1][j];
        }
        dp[i&1][s[i]-'0']++;
    }
    cout<<dp[1-s_size&1][0]<<endl;
    return 0;
}