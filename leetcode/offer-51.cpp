#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int tmp[50002];
    int Merge_num(int l, int r, vector<int>& nums){
        if(l >= r) return 0;
        int mid = (l+r)>>1;
        int ans = Merge_num(l, mid, nums);
        ans += Merge_num(mid+1, r, nums);
        int k=0, tm = mid+1;
        ans = 0;
        while(tm<= r && l <= mid){
            if(nums[l] > nums[tm]) ans += tm-mid;
            if(nums[tm] > nums[l])
                tmp[k++] = nums[tm],tm++;
            else nums[k++] = nums[l],l++;
        }
        while(tm <= r) tmp[k++] = nums[tm++];
        while(l <= mid) tmp[k++] = nums[l++];
        k=0;
        for(int i = l; i <=r; i++)
            nums[i] = tmp[k++];
    }

    int reversePairs(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        return Merge_num(l,r,nums);
    }
};

int main(){
    return 0;
}