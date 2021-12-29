//
// Created by cb on 2021/12/24.
//

#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> findSquare(vector<vector<int>> &matrix) {
        if (matrix.size() == 0) return {};
        vector<int> ans;
        int n = matrix.size();
        vector<vector<int>> dpc(n, vector<int>(n, 0));
        vector<vector<int>> dpr(n, vector<int>(n, 0));
        dpr[0][0] = 1-matrix[0][0];
        dpc[0][0] = 1-matrix[0][0];
        int maxans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dpr[i][j] = 1 - matrix[i][j];
                if(i > 0 && dpr[i][j]) dpr[i][j] += dpr[i-1][j];
                dpc[i][j] = 1 - matrix[i][j];
                if(j > 0 && dpc[i][j]) dpc[i][j] += dpc[i][j-1];
                for(int len = min(dpr[i][j], dpc[i][j]); len > maxans; len--) {
                    if (len > maxans && dpr[i][j - len + 1] >= len && dpc[i - len + 1][j] >= len) {
                        maxans = len;
                        ans = vector<int>{i - len + 1, j - len + 1, len};
                    }
                }
            }
        }
        return ans;
    }
};

/*
 * [[1, 1, 1, 1, 0, 1, 0, 1, 1, 1],
 *  [1, 1, 0, 0, 0, 0, 0, 0, 0, 0],
 *  [1, 1, 1, 1, 0, 1, 0, 1, 0, 1],
 *  [1, 1, 1, 1, 0, 0, 0, 0, 0, 0],
 *  [1, 0, 1, 0, 1, 1, 1, 1, 1, 1],
 *  [1, 1, 0, 0, 1, 0, 1, 0, 0, 1],
 *  [0, 0, 0, 1, 1, 1, 0, 1, 0, 1],
 *  [0, 0, 0, 1, 0, 1, 0, 1, 0, 1],
 *  [1, 0, 1, 0, 1, 1, 0, 1, 1, 1],
 *  [1, 1, 1, 0, 1, 0, 0, 1, 1, 1]]
 */