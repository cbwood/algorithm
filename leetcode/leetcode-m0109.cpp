#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        return s1.size() == s2.size() && (s2+s2).find(s1) != string::npos;
    }
};

int main(){

    return 0;
}