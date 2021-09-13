#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r=nums.size()-1;
        while(l < r){
            while((nums[l]&1)&&l<r) l++;
            while((!(nums[r]&1))&&l<r) r--;
            // cout << l<<" "<<r<<endl;
            if(!(nums[l]&1)){
                swap(nums[l], nums[r]);
                l++;
            }
            if((nums[r]&1)){
                swap(nums[l], nums[r]);
                r--;
            }
            // cout << l<<" "<<r<<endl;
        }return nums;
    }
};

int main(){
    vector<int> a{1,3,5};
    Solution so;
    vector<int> ans = so.exchange(a);
    for(auto &x: ans)
    cout<<x<<' ';
    return 0;
}