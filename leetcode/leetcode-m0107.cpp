#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int tmp;
        for(int i = 0; i < n/2;i++){
            for(int j = i; j < n-i-1; j++){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-1-j];
                matrix[n-i-1][n-1-j] = matrix[j][n-i-1];
                matrix[j][n-i-1] = tmp;
            }
        }
    }
};

int main(){
    
    return 0;
}