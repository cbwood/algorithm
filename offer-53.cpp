#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target)-nums.begin();
        return r-l;
    }
};

int main(){

    return 0;
}