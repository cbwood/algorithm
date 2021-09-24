//
// Created by cb on 2021/9/23.
//

#include "algorithm"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
    vector<int> findSwapValues(vector<int> &array1, vector<int> &array2) {
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < array1.size(); i++){
            sum1 += array1[i];
        }for(int i = 0; i < array2.size(); i++){
            sum2 += array2[i];
        }
        int n1 = array1.size()-1, n2 = array2.size()-1;
        std::sort(array1.begin(), array1.end());
        std::sort(array2.begin(), array2.end());
        bool check= true;
        if(sum1 < sum2){
            check = false;
            swap(sum2, sum1);
            swap(array2, array1);
            swap(n1, n2);
        }
        if(sum1-sum2>(array1[n1]-array2[0])*2) return {};
        int l = 0,r=0;
        while(l <= n1 && r <= n2){
            if(sum1-sum2 == (array1[l]-array2[r])*2)
                if(check)
                    return {array1[l], array2[r]};
                else
                    return {array2[r], array1[l]};
            else if(sum1-sum2 > (array1[l]-array2[r])*2)
                l++;
            else r++;
        }return {};
    }
};