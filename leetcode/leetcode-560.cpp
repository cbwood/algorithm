#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> ma;
        int ans = 0;
        ma[0] = 1;
        int pre = 0;
        for (auto &x: nums){
            pre += x;
            if(ma.find(pre-k) != ma.end())
                ans += ma[pre - k];
            ma[pre]++;
        }
        return ans;
    }
};


int main(){
    Solution so;
    vector<int> nums{1, 1, 1};
    printf("%d\n", so.subarraySum(nums, 2));
    return 0;
}