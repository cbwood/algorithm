#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        S = S.substr(0,length);
        string ans ="";
        for(auto &x: S){
            if(x == ' ')
                ans += "%20";
            else ans += x;
        }return ans;
    }
};

int main(){

    return 0;
}