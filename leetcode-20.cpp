#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(auto &x : s){
            if(sta.empty()){
                sta.push(x);
            }else {
                char ch = sta.top();
                if((ch == '{' && x == '}')||(ch == '(' && x == ')')||(ch == '[' && x == ']')){
                    sta.pop();
                }else sta.push(x);
            }
        }return sta.empty();
    }
};

int main(){
    Solution so;
    string s="()[]{}";
    cout << so.isValid(s);
    return 0;
}