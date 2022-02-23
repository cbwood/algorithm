#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0, r = s.size()-1;
        while(l < r){
            while(l < r && !((s[l] >= 'a' && s[l] <='z')||(s[l] >= 'A' && s[l] <='Z'))) l++;
        }
    }
};