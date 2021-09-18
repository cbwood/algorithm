//
// Created by cb on 2021/9/18.
//

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> bestLine(vector<vector<int>> &points) {
        int n = points.size();
        vector<int> ans{0,1};
        int num=2;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int numt = 2;
                for (int k = j+1; k < n; ++k) {
                    if(cross(points[i], points[j], points[k])) numt++;
                    if(numt+n-k-1 < num) break;
                }if(numt > num){
                    num = numt;
                    ans[0] = i;
                    ans[1] = j;
                }
            }return ans;
    }

    static bool cross(vector<int> &p1, vector<int> &p2, vector<int> &q){
        return (long)(p1[0]-q[0])*(p2[1]-q[1])-(long)(p1[1]-q[1])*(p2[0]-q[0]) == 0;
    }
};