//
// Created by cb on 2021/9/18.
//

#include "string"
#include "vector"
#include "algorithm"
using namespace std;


class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        vector<int>ans(2,0);
        vector<int> a(36, 0);
        for(int i = 0; i < 4; i++){
            if(solution[i] == guess[i]){
                ans[0]++;
                guess[i]='A';
            }
            else a[solution[i]-'A']++;
        }for(int i = 0; i < 4; i++){
            if(a[guess[i]-'A'] > 0){
                ans[1]++;
                a[guess[i]-'A']--;
            }
        }return ans;
    }
};

