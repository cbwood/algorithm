#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> ma;
        int num = 0;
        for(auto &x: s){
            ma[x]++;
            if(ma[x]&1) num++;
            else num--;
        }
        if(num == 1 && s.length()&1==1) return true;
        if(num == 0) return true;
        return false;
    }
};  

int main(){
    Solution so;
    cout<<so.canPermutePalindrome("dasds");
    return 0;
}