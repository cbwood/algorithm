#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        int i = n-1,j=0;
        while(i >= 0 && j < m){
            if(target == matrix[i][j]) return true;
            if(target > matrix[i][j]) j++;
            else i--;
        }return false;
    }
};

int main(){
    return 0;
}