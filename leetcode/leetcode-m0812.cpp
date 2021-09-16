//
// Created by cb on 2021/9/16.
//

#include "vector"
#include "string"
#include "cmath"
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> t;
        string ori = "";
        for(int i = 0; i < n; i++)
            ori = ori+".";
        vector<bool> visCol(n, false);
        vector<bool> visDial(2*n, false);
        vector<bool> visDiar(2*n, false);
        dfs(t, ori, n, visCol, 0, visDial, visDiar);
        return ans;
    }

    void dfs(vector<string> &t, string &ori, int &n, vector<bool> &visCol, int k, vector<bool> &visDial, vector<bool> &visDiar){
        if(n == k) {
            ans.push_back(t);
            return;
        }

        string tmp = ori;
        for(int i = 0; i < n; i++){
            if(!visCol[i] && !visDial[i+k] && !visDiar[i-k+n]){
                visCol[i] = true;
                visDial[i+k] = true;
                visDiar[i-k+n] = true;
                tmp[i] = 'Q';
                t.push_back(tmp);
                dfs(t,ori, n, visCol, k+1, visDial, visDiar);
                t.pop_back();
                tmp[i] = '.';
                visCol[i] = false;
                visDial[i+k] = false;
                visDiar[i-k+n] = false;
            }
        }
    }

private:
    vector<vector<string>> ans;

};
