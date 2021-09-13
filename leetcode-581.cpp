#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int al[n + 1], bl[n + 1];
        int ar[n + 1], br[n + 1];
        al[0] = 1;
        bl[0] = 1;
        ar[n - 1] = 1;
        br[n - 1] = 1;
        int k = nums[0];
        for (int i = 1; i < n; ++i){
            if(nums[i] >= k)
                bl[i] = 1;
            else
                bl[i] = 0;
            k = max(k, nums[i]);
            if(nums[i] >= nums[i-1])
                al[i] = al[i - 1];
            else
                al[i] = 0;
        }
        k = nums[n - 1];
        for (int i = n - 2; i >= 0; --i){
            if(nums[i] <= k)
                br[i] = 1;
            else
                br[i] = 0;
            k = min(k, nums[i]);
            if(nums[i] <= nums[i+1])
                ar[i] = ar[i + 1];
            else
                ar[i] = 0;
        }
        int l = 0, r = n-1;
        for (int i = 0; i < n; ++i){
            if(al[i]&&bl[i]&&br[i])
                l = max(l, i+1);
            if (ar[i] && br[i] && bl[i])
                r = min(r, i-1);
        }
        return max(0, r - l + 1);
    }
};


int main(){
    Solution so;
    vector<int> nums{2, 6, 4, 8, 10, 9, 15};
    printf("%d\n", so.findUnsortedSubarray(nums));
}