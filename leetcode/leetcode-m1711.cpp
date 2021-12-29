//
// Created by cb on 2021/12/20.
//

#include "string"
#include "vector"
#include "algorithm"
#include "map"
#include "iostream"
#include "climits"

using namespace std;
class Solution {
public:
    int findClosest(vector<string> &words, string word1, string word2) {
        map<string, vector<int>> ma;
        for (int i = 0; i < words.size(); ++i) {
            ma[words[i]].push_back(i);
        }
        int ans = INT_MAX;
        int k1=0,k2=0;
        while (k1 < ma[word1].size() && k2 < ma[word2].size()){
            ans = min(ans, abs(ma[word1][k1]-ma[word2][k2]));
            if(ma[word1][k1] > ma[word2][k2]) k2++;
            else k1++;
        }
        return ans;
    }
};

int main() {
    map<string, vector<int>> ma;
    ma["word"].push_back(1);
    cout << ma["word"][0] << endl;
    return 0;
}