#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int> que;
        
        for(auto &x: input){
            if(que.size()< k)
                que.push(x);
            else {
                que.push(x);
                que.pop();
            }
        }vector<int> ans;
        if(k > input.size()) return ans;
        while ((!que.empty())){
            ans.push_back(que.top());
            que.pop();
        }return ans;
    }
};
