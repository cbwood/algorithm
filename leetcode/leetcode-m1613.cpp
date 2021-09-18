//
// Created by cb on 2021/9/18.
//

#include "vector"
#include "algorithm"
#include "cmath"
using namespace std;

class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        vector<double> ans(4);
        double pi = acos(-1);
        if(square1[0] < square2[0]) swap(square1, square2);
        if(square1[0] == square2[0] && square1[1] > square2[1]) swap(square2, square1);
        ans[0] = square1[0]+square1[2]*1.0/2;
        ans[1] = square1[1]+square1[2]*1.0/2;
        ans[2] = square2[0]+square2[2]*1.0/2;
        ans[3] = square2[1]+square2[2]*1.0/2;
        if(ans[0] == ans[2]){
            ans[1] = min(min(square1[1] +square1[2],square2[1]+square2[2]), min(square1[1],square2[1]));
            ans[3] = max(max(square1[1] +square1[2],square2[1]+square2[2]), max(square1[1],square2[1]));
        }else if(ans[1] == ans[3]){
            ans[0] = min(min(square1[0] + square1[2] ,square2[0]+square2[2]), min(square1[0],square2[0]));
            ans[2] = max(max(square1[0] + square1[2] ,square2[0]+square2[2]), max(square1[0],square2[0]));
        }else{

            double k = (ans[1]-ans[3])*1.0/(ans[0]-ans[2]);
            double b = ans[1]-k*ans[0];
            if(k > 1 || k < -1){
                if(square1[1] > square2[1]) swap(square2, square1);
                ans[1] = min(square1[1], square2[1]);
                ans[0] = (ans[1]-b)/k;
                ans[3] = max(square1[1]+square1[2],square2[1]+square2[2]);
                ans[2] = (ans[3]-b)/k;
            }else{
                if(square1[0] > square2[0]) swap(square2, square1);
                ans[0] = min(square1[0], square2[0]);
                ans[2] = max(square2[0]+square2[2], square1[0]+square1[2]);
                ans[1] = k*ans[0]+b;
                ans[3] = k*ans[2]+b;
            }
        }if(ans[0] > ans[2]){
            swap(ans[0], ans[2]);
            swap(ans[1], ans[3]);
        }if(ans[0] == ans[2] && ans[1] > ans[3]){
            swap(ans[0], ans[2]);
            swap(ans[1], ans[3]);
        }
        return ans;
    }
};