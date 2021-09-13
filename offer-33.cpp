#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<int>& postorder, int l, int r){
        if(l >= r) return true;
        int k = l;
        for(int i = r-1; i >= l; i--){
            if(postorder[r] > postorder[i]){
                k = i;
                break;
            }
        }for(int i = l; i <= k; ++i)
            if(postorder[i]> postorder[r]) return false;
        for(int i = k +1; k < r; ++i)
            if(postorder[i]<postorder[r]) return false;
        if(!dfs(postorder, l, k)) return false;
        if(!dfs(postorder, k+1, r-1)) return false;
        return true;
    };
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        return dfs(postorder, 0,n-1);
    }
};

int main(){
    return 0;
}