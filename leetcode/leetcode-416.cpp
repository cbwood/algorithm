#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &x: nums)
            sum += x;
        int n = nums.size();
        int dp[10002];
        if(sum&1)
            return 0;
        sum /= 2;
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = sum; j >= nums[i]; j--){
                dp[j] = dp[j-nums[i]];
            }
        return dp[sum];
    }
};

int main(){
    Solution so;
    vector<int> nums{1, 2, 5};
    printf("%d", so.canPartition(nums));
    return 0;
}