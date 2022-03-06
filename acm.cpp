#include "bits/stdc++.h"

using namespace std;

inline int gcd(int a, int b) {
    return b > 0 ? gcd(b, a % b) : a;
}

inline int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int> &nums) {
        vector<int> ans;
        int n = nums.size();
        if (n == 0) return ans;
        int pre = nums[0];
        for (int i = 1; i < n; i++) {
            if (gcd(pre, nums[i]) != 1) {
                pre = lcm(pre, nums[i]);
            } else {
                ans.push_back(pre);
                pre = nums[i];
            }
        }
        ans.push_back(pre);

        return ans;
    }
};