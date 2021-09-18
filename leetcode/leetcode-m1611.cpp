//
// Created by cb on 2021/9/18.
//

#include "vector"
#include "algorithm"
#include "set"

using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> ans(k + 1);
        if (k == 0) return {};
        if (longer == shorter) return {k * longer};
        for (int i = 0; i <= k; i++)
            ans[i] = longer * i + shorter * (k - i);
        return ans;
    }
};