#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void solve(vector<int> &a, int x, int f){
    int k = 0;
    while(x){
      int t = x&1;
      x = x >>1;
      a[k++] += f*t;
    }
  }

  bool  check(vector<int> &a){
    for(auto &x: a){
      if(x > 1) return false;
    }
    return true;
  }
  int longestNiceSubarray(vector<int>& nums) {
    vector<int> bits(64, 0);
    int l = 0,r = 0;
    int n = nums.size();
    int ans = 1;
    while (r < n){
      solve(bits, nums[r], 1);
      while(!check(bits)){
        solve(bits, nums[l++], -1);
      }
      ans = max(ans, r-l+1);
      r++;
    }
    return ans;
  }
};