#include<bits/stdc++.h>
using namespace std;
namespace solution1{
    class Solution {
    public:
        int movingCount(int m, int n, int k) {
            queue<int> que;
            int dx[4] = {0,0,1,-1};
            int dy[4] = {1,-1,0,0};
            que.push(0);
            unordered_map<int, bool> ma;
            ma[0] = true;
            int ans = 1;
            while(!que.empty()){
                int tmp = que.front();
                que.pop();
                int x = tmp/n;
                int y = tmp%n;
                for(int i = 0; i < 4; ++i){
                    int sx = dx[i]+x;
                    int sy = dy[i]+y;
                    if(check(sx,sy,k,m,n) && ma[sx*n+sy] == false){
                        que.push(sx*n+sy);
                        ans ++;
                        ma[sx*n+sy] = true;
                    }
                }
            }return ans;
        }
        bool check(int x, int y, int k, int m, int n){
            if(x >= 0 && x<m && y >= 0 && y < n){
                int sum = 0;
                while (x){
                    sum += x%10;
                    x /= 10;
                }
                while (y){
                    sum += y%10;
                    y /= 10;
                }
                if(sum <= k) return true;
            }return false;
        }
    };
}

namespace solution2{
    class Solution {
        public:
            int dfs(int x, int y, int sx, int sy, int m, int n, int k, vector<vector<bool>> &vis){
                if( x>= m || y >= n || vis[x][y] || sx+sy>k) return 0;
                vis[x][y] = 1;
                return 1
                +dfs(x,y+1,sx,(y+1)%10 == 0?sy-8:sy+1,m,n,k,vis)
                +dfs(x+1,y,(x+1)%10 == 0?sx-8:sx+1,sy,m,n,k,vis);
            }

            int movingCount(int m, int n, int k) {
                vector<vector<bool>> vis(m, vector<bool>(n,false));
                return dfs(0,0,0,0,m,n,k,vis);
            }
        };
}
int main(){
    solution2::Solution so;
    cout << so.movingCount(3,2,17)<<endl;
    return 0;
}