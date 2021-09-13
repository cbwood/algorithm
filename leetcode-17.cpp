#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int len = digits.length();
        if(len > 0)
            dfs(0,digits,"", ans);
        return ans;
    }
    void dfs(int i, string digits, string x, vector<string> &ans){
        if(i == digits.length()){
            ans.push_back(x);
            return ;
        }
        int y = digits[i]-'0';
        int q=3;
        if(y==7||y==9) q=4;
        for(int j=0; j < q; ++j){
            string yy; 
            if(y > 7) yy= char('a'+(y-2)*3+j+1);
            else yy = char('a'+(y-2)*3+j);
            dfs(i+1, digits,x+yy ,ans);
        }
    }
};


int main(){
    string s;
    //cin >> s;
    s="7";
    Solution so;
    vector<string> ans = so.letterCombinations(s);
    for(auto &x : ans)
        cout << x << endl;
    return 0;
}