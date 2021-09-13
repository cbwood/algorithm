#include<bits/stdc++.h>
using namespace std;

class Solution {
    int a,b,c, tmpa, tmpb, tmpc;
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        a=b=c = 0;
        a = -prices[0];
        for(int i = 1; i < n; ++i){
            tmpa=a;
            tmpb = b;
            tmpc = c;
            c = max(tmpc, tmpb);
            a = max(tmpa, tmpc-prices[i]);
            b = tmpa+prices[i];
           
        }return max(b, c);
    }
};

int main(){
    Solution so = Solution();
    vector<int> v {1,2,3,0,2};
    printf("%d\n", so.maxProfit(v));
    return 0;
}