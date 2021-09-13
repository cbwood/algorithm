#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> se(nums.size(), 0);
        for(auto &x: nums){
            if(se[x] == 1)
                return x;
            else se[x] += 1;
        }return 1;
    }
};


int main(){
    Solution so;
    vector<int> p{2, 3, 1, 0, 2, 5, 3};
    cout << so.findRepeatNumber(p)<<endl;
    return 0;
}