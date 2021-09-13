#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vis[10]={0};
    vector<string> ans;
    int n;
    void dfs(string tmp, int k, string s){
        if(k == n){
            ans.push_back(tmp);
            return ;
        }char pre = '.';
        for(int i = 0; i < n; i++)
            if(!vis[i] && s[i] != pre){
                pre = s[i];
                vis[i] = 1;
                dfs(tmp+s[i],k+1, s);
                vis[i] = 0;
            }
    }

    vector<string> permutation(string s) {
        n = s.length();
        sort(s.begin(), s.end());
        dfs("", 0,s);
        return ans;
    }
};

int main(){

    return 0;
}