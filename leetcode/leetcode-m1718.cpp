//
// Created by cb on 2021/12/21.
//

#include "algorithm"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<int> shortestSeq(vector<int> &big, vector<int> &small) {
        unordered_map<int, int> ma, mb;
        for (auto &x: small)
            mb[x] = 1;
        int l = 0, r = 0;
        vector<int> ans;
        int ansmax = INT_MAX;
        int n = big.size();
        int num = 0;
        while (r < n) {
            ma[big[r++]]++;
            if (mb[big[r - 1]] == 1 && ma[big[r - 1]] == 1) num++;
            while (l < r && (mb[big[l]] == 0 || r - l >= ansmax || ma[big[l]] > 1)) {
                if(mb[big[l]] == 1 && ma[big[l]] == 1) num--;
                ma[big[l]]--;
                l++;
            }
            if (r - l < ansmax && num == small.size()) {
                ansmax = r - l;
                ans.clear();
                ans.push_back(l);
                ans.push_back(r - 1);
            }
        }
        return ans;
    }
};