//
// Created by cb on 2021/9/15.
//

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> ans;
        int t = 0;
        vector<int> a(w, 0);
        for(int i = x1; i <= x2; i++)
            a[i] = 1;
        for(int i = 0; i < w; i++){
            if(i && i%32 == 0){
                ans.push_back(t);
                t = 0;
            }t = t * 2 + a[i];
        }return ans;
    }
};

int main(){
    return 0;
}