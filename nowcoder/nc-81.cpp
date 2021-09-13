#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        int n = numbers.size();
        map<int, int> ma;
        for(int i = 0; i < n; i++){
            if(ma[target-numbers[i]])
                return vector<int>{ma[target-numbers[i]], i+1};
            ma[numbers[i]] = i+1;
        }return vector<int>{};
    }
};