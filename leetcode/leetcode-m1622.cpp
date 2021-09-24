//
// Created by cb on 2021/9/23.
//

#include "vector"
#include "string"
#include "algorithm"
#include "climits"
#include "map"

using namespace std;

class Solution {
public:
    vector<string> printKMoves(int K) {
        int op = 0;
        int sx = st, sy = st;
        int minx = st, maxx = st, miny = st, maxy = st;
        map<long, short> ma;
        st*=3;
        char opt[4]={'R','D','L','U'};
        for (int i = 0; i < K; i++) {
            long ix = (long)sx*st+sy;
            if (ma[ix] == 0) {
                op = (op + 1) % 4;
            }
            else op = (op + 3) % 4;
            sx = sx + dx[op];
            sy = sy + dy[op];
            ma[ix] = 1 - ma[ix];
            minx = min(minx, sx);
            maxx = max(maxx, sx);
            miny = min(miny, sy);
            maxy = max(maxy, sy);
        }
        int n = maxx-minx+1, m = maxy-miny+1;
        string tmp;
        for(int i = 0; i < m; i++)
            tmp += c;
        vector<string> ans(n, tmp);
        for(auto &x: ma){
            if(x.second == 1){
                ans[x.first/st-minx][x.first%st-miny] = 'X';
            }
        }
        ans[sx-minx][sy-miny] = opt[op];
        return ans;
    }

private:
    const string c = "_";
    int dx[4] = {0, 1, 0, -1,};
    int dy[4] = {1, 0, -1, 0};
    int st = 100003;
};
