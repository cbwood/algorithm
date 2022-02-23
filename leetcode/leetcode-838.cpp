#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int i = 0, j = 0;
        char left = 'L', right = 'R';
        while(i < n){
            int j  = i;
            while(j < n && dominoes[j] == '.') j++;
            right = j < n ? dominoes[j]: 'R';
            if(left == right){
                while(i < j){
                    dominoes[i] = left;
                    i++;
                }
            }else if(left == 'R' && right == 'L'){
                int k = j-1;
                while(i < k){
                    dominoes[i++] = left;
                    dominoes[k--] = right;
                }
            }
            i = j + 1;
            left = right;
        }return dominoes;
    }
};
