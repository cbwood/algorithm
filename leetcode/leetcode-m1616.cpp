//
// Created by cb on 2021/9/23.
//

#include "vector"
#include "algorithm"
#include "climits"
using namespace std;

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        int l = -1, r = -1;
        int n = array.size()-1;
        if(n < 0) return {-1, -1};
        int minr = INT_MAX;
        for(int i = n; i >= 0; --i){
            if(array[i] > minr)
                l = i;
            else minr = min(minr, array[i]);
        }
        int maxl = INT_MIN;
        for(int i = 0; i <= n; i++){
            if(array[i] < maxl)
                r = i;
            else maxl = max(maxl, array[i]);
        }return {l, r};
    }
};