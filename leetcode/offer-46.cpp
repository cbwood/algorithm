#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs( string num, int k, int tmp, int &len){
        if(tmp>=26) return 0;
        if(k >= len){
            return 1;
        }
        int ans = 0;
        ans += dfs( num, k+1, tmp*10+num[k]-'0', len);
        if(tmp)
            ans += dfs( num, k+1, num[k]-'0', len);
        return ans;
    }
    int translateNum(int num) {
        string nums = to_string(num);
        int len = nums.length();
        return dfs(nums, 0, 0, len);
    }
};

int main(){

    return 0;
}