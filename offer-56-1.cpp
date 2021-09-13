#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto &x: nums)
            ans ^= x;
        int k=1;
        int a=0,b=0;
        while((k&ans) == 0) k <<= 1;
        for(auto &x: nums){
            if(x&k) a^= x;
            else b^= x;
        }return vector<int> {a,b};
    }
};

int main(){

    return 0;
}