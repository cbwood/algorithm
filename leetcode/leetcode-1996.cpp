/*
 * @File Name          :leetcode-1996.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/28 10:30
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        sort(properties.begin(), properties.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
        int ans = 0;
        int maxr1 = properties[properties.size() - 1][1];
        for (int i = properties.size() - 2; i >= 0; i--) {
            if (properties[i][1] < maxr1)
                ans++;
            maxr1 = max(maxr1, properties[i][1]);
        }
        return ans;
    }
};