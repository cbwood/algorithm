//
// Created by cb on 2021/9/17.
//

#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int xx=matrix.size()-1, yy=0;
        while(xx >= 0 && yy < matrix[0].size()){
            if(matrix[xx][yy] > target) xx--;
            else if(matrix[xx][yy] < target) yy++;
            else return 1;
        }return 0;
    }
};

int main() {
    Solution so;
    vector<vector<int>> a{{}
    };
    cout<<so.searchMatrix(a, 5)<<endl;
    return 0;
}