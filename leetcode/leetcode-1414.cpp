/*
 * @File Name          :leetcode-1414.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/2/3 14:49
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "algorithm"
#include "vector"

using namespace std;

const int maxn = 1e9;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> a;
        a.push_back(1);
        a.push_back(1);
        int t = 1, p = 1, tmp;
        while (t + p <= k) {
            a.push_back(t + p);
            tmp = t;
            t = t + p;
            p = tmp;
        }
        a.push_back(t + p);
        int ans = 0;
        while (k > 0) {
            t = lower_bound(a.begin(), a.end(), k) - a.begin();
            ans++;
            if (a[t] > k) t--;
            k -= a[t];
        }
        return ans;
    }
};