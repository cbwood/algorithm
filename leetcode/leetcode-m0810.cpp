//
// Created by cb on 2021/9/15.
//

#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<bool> vis(10000, false);
        vis[sr*50+sc] = true;
        dfs(image, sr, sc, newColor, image[sr][sc], vis);
        image[sr][sc] = newColor;
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int k, vector<bool> &vis){

        for(int i = 0; i < 4; i++){
            int sx = sr + dx[i];
            int sy = sc + dy[i];
            if(sx >= 0 && sy >= 0 && sx < image.size() && sy<image[0].size() && image[sx][sy] == k && !vis[sx*50+sy]){
                image[sx][sy] = newColor;
                vis[sx*50+sy] = true;
                dfs(image, sx, sy, newColor, k, vis);
            }
        }
    }

private:
    const int dx[4] = {1,-1,0,0};
    const int dy[4] = {0,0,1,-1};
};
