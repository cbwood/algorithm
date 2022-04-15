/*
 *@File Name          :ctrip-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/14 19:13
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    string s;
    cin >> s;
    unordered_map<int, vector<int>> map_num;
    for (int i = 0; i < n; i++) {
        int color = 0;
        if (s[i] == 'R')
            color = 1;
        if (map_num.count(nums[i]) == 0){
            map_num[nums[i]].push_back(0);
            map_num[nums[i]].push_back(0);
        }
        map_num[nums[i]][color]++;
    }
    long long ans = 0;
    for(auto &x: map_num){
        ans += x.second[0]*x.second[1];
    }
    cout<<ans<<endl;
    return 0;
}