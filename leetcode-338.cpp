#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        ans[0] = 0;
        if(!num)
            return ans;
        ans[1] = 1;
        for(int i = 2; i <= num; ++i)
            ans[i] = ans[i/2] + (i&1);
        return ans;
    }
};

int main(){
    Solution so;
    vector<int> ans = so.countBits(100);
    for(int i = 0;i < 100; ++i)
        printf("%d : %d\n", i, ans[i]);
    return 0;
}