#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    bool vis[7];

    void dfs(vector<int>& nums, vector<int>& t){
        if(t.size() == nums.size()){
            ans.push_back(t);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!vis[i]){
                vis[i] = true;
                t.push_back(nums[i]);
                dfs(nums, t);
                t.pop_back();
                vis[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        memset(vis, false, sizeof vis);
        vector<int> t;
        dfs(nums, t);
        return ans;
    }
};