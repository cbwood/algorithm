#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
      multiset<int> se;
      for(auto &x: nums1){
        se.insert(x);
      }
      for(int i = 0; i < nums1.size(); i++){
        auto t = se.upper_bound(nums2[i]);
        if(t == se.end()){
          t = se.begin();
        }
        nums1[i] = *t;
        se.erase(t);
      }
      return nums1;
    }
};

int main(){
  
  return 0;
}