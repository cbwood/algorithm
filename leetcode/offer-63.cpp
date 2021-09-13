#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int pre = prices[0];
        for(auto &x : prices){
            ans = max(ans, x-pre);
            pre = min(pre, x);
        }return ans;
    }
};

int main(){
    return 0;
}