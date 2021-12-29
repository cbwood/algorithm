//
// Created by cb on 2021/12/27.
//

#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
using namespace std;

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        vector<int> sumx(matrix[0].size(), 0);
        vector<int> ans(4);
        int summ = 0;
        int maxsum = INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) sumx[j]=0;
            for(int j = i; j < n; j++){
                summ = 0;
                int lj = 0;
                for(int k = 0; k < m; k++){
                    sumx[k] += matrix[j][k];
                    if(summ > 0){
                        summ += sumx[k];
                    }else {
                        summ = sumx[k];
                        lj = k;
                    }
                    if(summ > maxsum){
                        maxsum = summ;
                        ans = vector<int>{i, lj, j, k};
                    }
                }
            }
        }return ans;
    }
};

/*
 * [[9,-8,1,3,-2],
 *  [-3,7,6,-2,4],
 *  [6,-4,-4,8,-7]]
 */