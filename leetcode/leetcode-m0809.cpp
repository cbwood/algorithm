//
// Created by cb on 2021/9/15.
//

#include "string"
#include "vector"
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dfs(n*2, "", 0, 0);
        return ans;
    }

    void dfs(int n, string s, int l, int r){
        if(n == 0){
            if(l == r)
                ans.push_back(s);
            return;
        }
        if(r > l) return;
        if(l > r+n) return;
        dfs(n-1, s+')', l, r+1);
        dfs(n-1, s+'(', l+1, r);
    }

private:
    vector<string> ans;
};

int main(){
    return 0;
}