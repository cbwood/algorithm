//
// Created by cb on 2021/9/24.
//

#include "vector"
#include "string"
#include "algorithm"
#include "map"

using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string> &array) {
        map<int, int> ma;
        vector<int> sump(array.size() + 1, 0);
        for (int i = 1; i < array.size() + 1; i++) {
            bool check = true;
            for (const auto &x: array[i - 1]) {
                if (x < '0' || x > '9') {
                    check = false;
                    break;
                }
            }
            if (check) sump[i] = sump[i - 1] + 1;
            else sump[i] = sump[i - 1] - 1;
            ma[sump[i]] = i;
        }
        int l = 0, r = ma[0];
        for (int i = 1; i <= array.size(); i++) {
            if (ma[sump[i]] - i + 1 > r - l) {
                l = i - 1;
                r = ma[sump[i]];
            }
        }
        return vector<string>(array.begin() + l, array.begin() + r);
    }
};