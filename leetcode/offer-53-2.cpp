#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int mid;
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid] == mid)
                l = mid+1;
            else r=mid-1;
        }return l;
    }
};

int main(){
    return 0;
}