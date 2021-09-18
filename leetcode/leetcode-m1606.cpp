//
// Created by cb on 2021/9/18.
//

#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int na = a.size(), nb = b.size();
        int la = 0, lb = 0;
        long long ans = 2147483647;
        while(la < na && lb < nb){
            ans = min(ans, abs((long long)a[la]-b[lb]));
            if(a[la] <= b[lb] && la < na) la++;
            else if(a[la] >= b[lb] && lb < nb) lb++;
        }
        return ans;
    }
};