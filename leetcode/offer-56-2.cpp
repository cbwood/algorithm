#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit[40] = {0};
        int k = 0;
        for(auto &x: nums){
            k=0;
            while(x){
                bit[k++] += x&1;
                x>>=1;
            }
        }int ans=0;
        for(int i=31;i>=0;i--){
            ans = ans*2+bit[i]%3;
        }return ans;
    }
};

int main(){
    return 0;
}