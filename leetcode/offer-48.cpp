#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> ma;
        for(auto &c: s)
            ma[c] = 0;
        int k=0,len = s.length();
        int ans = 1;
        for(int i = 0; i < len; i++){
            ma[s[i]]++;
            while(k <= i && ma[s[i]] > 1){
                ma[s[k]]--;
                k++;
            }ans = max(ans, i-k+1);
        }return ans;
    }
};

int main(){
    return 0;
}