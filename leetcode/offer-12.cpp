#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n,m;
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                if(board[i][j] == word[0]){
                    char tmp = board[i][j];
                    board[i][j] = '1';
                    if(dfs(i, j, 1, word, board)) return true;
                    board[i][j] = tmp;
                }
            }
        return false;
    }
    
    bool dfs(int i, int j, int idx, string word, vector<vector<char>>& board){
        if(idx == word.length()) return true;
        for(int k = 0; k < 4; ++k){
            int x = i+dx[k];
            int y = j+dy[k];
            if(x>=0&&x<n&&y>=0&&y<m&&word[idx] == board[x][y]){
                char tmp = board[x][y];
                board[x][y] = '1';
                if(dfs(x, y, idx+1, word, board)) return true;
                board[x][y] = tmp;
            }
        }return false;
    }

};

int main(){

    return 0;
}