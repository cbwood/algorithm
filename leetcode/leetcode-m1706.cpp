//
// Created by cb on 2021/9/24.
//

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
public:
    int numberOf2sInRange(int n) {
        int pos = 0;
        while(n){
            bits[pos++] = n%10;
            n /= 10;
        }return dfs(pos-1, true, 0);
    }

    int dfs(int pos, bool limit, int num2 ){
        if(pos == -1) return num2;
        if(!limit&&dp[pos][num2] != -1) return dp[pos][num2];
        int up = limit ? bits[pos]: 9;
        int ans = 0;
        for(int i = 0; i <= up; i++){
            ans += dfs(pos-1, limit&&i==bits[pos],num2+(i==2));
        }if(!limit) dp[pos][num2] = ans;
        return ans;
    }

private:
    vector<int> bits = vector<int>(20, 0);
    vector<vector<int>> dp = vector<vector<int>>(20, vector<int>(100,-1));
};