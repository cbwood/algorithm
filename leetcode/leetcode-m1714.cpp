//
// Created by cb on 2021/12/20.
//

#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int> que;
        for(auto &x: arr){
            que.push(x);
            while (que.size() > k) que.pop();
        }vector<int> ans;
        while(!que.empty()){
            ans.push_back(que.top());
            que.pop();
        }return ans;
    }
};