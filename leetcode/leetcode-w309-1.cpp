#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool checkDistances(string s, vector<int>& distance) {
    for(int i = 0; i < 26; i++){
      int l = -1, r = -1;
      for(int j = 0; j < s.size(); j++){
        if(s[j]-'a' == i){
          if(l == -1) l =j;
          else r = j;
        }
      }
      if(l != -1){
        if(r-l -1!= distance[i]) return false;
      }
    }
    return true;
  }
};