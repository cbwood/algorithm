#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        for(int i = 0; i < (n+1)/2; ++i){
            int j = i;
            while(j < m-i-1) ans.push_back(matrix[i][j++]);
            j = n-i-1;
            while(j >= i+1) ans.push_back(matrix[n-(j--)-1][m-i-1]);
            while(j < n-i-1) ans.push_back(matrix[n-i-1][n-(j++)-1]);
            while(j >= i+1) ans.push_back(matrix[j--][i]);
        }return ans;
    }
};

int main(){


    return 0;
}