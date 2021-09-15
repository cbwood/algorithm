//
// Created by cb on 2021/9/15.
//

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> t;
        if(obstacleGrid[0][0] == 0){
            t.push_back({0,0})
            dfs(obstacleGrid, 0, 0, t);
        }
        return ans;
    }

    void dfs(vector<vector<int>>& obstacleGrid, int sx, int sy, vector<vector<int>> &t){
        if(sx == obstacleGrid.size()-1 && sy == obstacleGrid[0].size()-1){
            ans = t;
            return;
        }if(ans.size()>0) return;
        if(sx+1<obstacleGrid.size()&&obstacleGrid[sx+1][sy] == 0){
            obstacleGrid[sx+1][sy] = 1;
            t.push_back({sx+1,sy});
            dfs(obstacleGrid, sx+1, sy, t);
            t.pop_back();
        }
        if(sy+1<obstacleGrid[0].size()&&obstacleGrid[sx][sy+1] == 0){
            obstacleGrid[sx][sy+1] = 1;
            t.push_back({sx,sy+1});
            dfs(obstacleGrid, sx, sy+1, t);
            t.pop_back();
        }
    }

private:
    vector<vector<int>> ans;
};

int main(){
    return 0;
}