#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Merge(vector<long long> &sum, int lower, int upper, int left, int right){
        if(left >= right) return 0;
        int mid = (left+right)/2;
        int ans1 = Merge(sum, lower, upper, left, mid);
        int ans2 = Merge(sum, lower, upper, mid+1, right);
        int ans = ans1+ans2;
        int i=left, l = mid+1, r = mid+1;
        while(i <= mid){
            while(l <= right && sum[l]-sum[i]< lower) l++;
            while(r <= right && sum[r]-sum[i]<= upper) r++;
            ans += (r-l);
            i++;
        }vector<long long> tmp(right-left+1);
        int p1 = left, p2 = mid+1;
        int k = 0;
        while(p1 <= mid && p2 <= right){
            if(sum[p1] > sum[p2])
                tmp[k] = sum[p2++];
            else
                tmp[k] = sum[p1++];
            k++;
        }while(p1 <= mid) tmp[k++] = sum[p1++];
        while(p2 <= right) tmp[k++] = sum[p2++];
        for(int i = left; i <= right; i++)
            sum[i] = tmp[i-left];
        return ans;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sum{0};
        long long s = 0;
        for(auto &x: nums){
            s += x;
            sum.push_back(s);
        }return Merge(sum, lower, upper, 0, sum.size()-1);
    }
};

int main(){
    Solution so;
    vector<int> nums{-2147483647,0,-2147483647,2147483647};
    cout << so.countRangeSum(nums, -564, 3864) << endl;
    return 0;
}