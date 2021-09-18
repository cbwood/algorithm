//
// Created by cb on 2021/9/17.
//

#include "vector"
#include "string"
#include "algorithm"
#include "iostream"

using namespace std;


class Solution {
public:
    string tictactoe(vector<string> &board) {
        int n = board.size();
        bool blank = false;
        bool checkl = true, checkr = true;
        for (int i = 0; i < n; i++) {
            bool check1 = true, check2 = true;
            for (int j = 1; j < n; j++) {
                if (board[i][j] != board[i][j - 1] || board[i][j] == ' ')
                    check1 = false;
                if (board[i][j] == ' ' || board[i][j - 1] == ' ')
                    blank = true;
                if (board[j - 1][i] != board[j][i] || board[j][i] == ' ')
                    check2 = false;
            }
            if (check1) return string(1, board[i][0]);
            if (check2) return string(1, board[0][i]);
            if (i > 0) {
                if (board[i][i] != board[i - 1][i - 1] || board[i][i] == ' ')
                    checkl = false;
                if (board[i][n - i - 1] != board[i - 1][n - i] || board[i][n - i - 1] == ' ')
                    checkr = false;
            }
        }
        if (checkl) return string(1, board[0][0]);
        if (checkr) return string(1, board[0][n - 1]);
        if (blank) return "Pending";
        return "Draw";
    }
};


int main() {
    Solution so;
    vector<string> a{"O X", " XO", "X O"};
    cout << so.tictactoe(a) << endl;
}