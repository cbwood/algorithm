#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> que;
        int n = T.size();
        vector<int> ans(n,0);
        que.push(n-1);
        for(int i = n-2; i >= 0; --i){
            int k = i;
            while(!que.empty() && T[que.top()] <= T[i]){
                que.pop();
            }
            if(!que.empty())
                k = que.top();
            que.push(i);
            ans[i] = k-i;
        }return ans;
    }
};

int main(){
    Solution  so;
    vector<int> T{73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = so.dailyTemperatures(T);
    for(auto &x: ans)
        cout << x << ' ';
    cout << endl;
    return 0;
}