/*
 *@File Name          :ctrip-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/14 19:34
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

int main(){
    string s;
    cin >> s;
    int s_size = s.size();

    vector<vector<int>> que(2);

    for(int i = 0; i < s.size(); i++){
        que[s[i]-'0'].emplace_back(i);
    }
    long long ans = 0;
    if(que[0].size() > que[1].size()){
        for(int i = 0; i < s_size; i++){
            ans += max(0, que[i&1][i/2]-i);
        }
        cout<<ans<<endl;
    }else if(que[0].size() < que[1].size()){
        for(int i = 0; i < s_size; i++){
            ans += max(0, que[1-i&1][i/2]-i);
        }
        cout<<ans<<endl;
    }else {
        long long ans1 = 0;
        long long ans2 = 0;
        for(int i = 0; i < s_size; i++){
            ans1 += max(0, que[i&1][i/2]-i);
        }
        for(int i = 0; i < s_size; i++){
            ans2 += max(0, que[1-i&1][i/2]-i);
        }
        cout<<min(ans1, ans2)<<endl;
    }return 0;
}