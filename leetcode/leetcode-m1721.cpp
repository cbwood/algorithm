//
// Created by cb on 2021/12/24.
//

#include "algorithm"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        vector<int> pre(height.size()+1, 0)
        int maxpre= 0;
        for(int i = 0; i < height.size(); i++){
            maxpre = max(maxpre, height[i]);
            pre[i] = maxpre;
        }
        int maxorder = 0;
        for(int i = height.size()-1; i >= 0; i--){
            maxorder = max(height[i], maxorder);
            ans += min(maxorder, pre[i]) - height[i];
        }
        return ans;
    }
};