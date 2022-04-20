/*
 *@File Name          :offer2-013.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/18 14:48
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;


class NumMatrix {
private:
    vector<vector<int>> matrix;
public:

    NumMatrix(vector<vector<int>> &matrix) {
        this->matrix = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 1; i <= matrix.size(); ++i)
            for (int j = 1; j <= matrix[0].size(); ++j)
                this->matrix[i][j] = this->matrix[i - 1][j] + this->matrix[i][j - 1] - this->matrix[i - 1][j - 1] +
                                     matrix[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row2++;
        col2++;
        return this->matrix[row2][col2] - this->matrix[row1][col2] - this->matrix[row2][col1] +
               this->matrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */