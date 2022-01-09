/*
 * @File Name          :leetcode-89.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/8 15:04
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include <cstring>
#include "vector"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.reserve(1<<n);
        ans.push_back(0);
        for(int i = 0; i < n; i++){
            for(int j = ans.size()-1; j >= 0; j--)
                ans.push_back(ans[j]|(1<<i));
        }return ans;
    }
};

//class Solution {
//public:
//    vector<int> ans;
//    bool vis[100000];
//    vector<int> grayCode(int n) {
//        int num = (1<<n);
//        ans.push_back(0);
//        memset(vis, false, sizeof(vis));
//        vis[0] = true;
//        dfs(1, num, 0, n);
//        return ans;
//    }
//
//    bool dfs(int cur, int &num, int pre, int &n){
//        if(cur == num){
//            if((pre&(pre-1)) == 0) return true;
//            return false;
//        }
//        for(int i = 0; i < n; i++){
//            int x = (1<<i)^pre;
//            if(vis[x] == 0){
//                vis[x] = 1;
//                ans.push_back(x);
//                if(dfs(cur+1, num, x, n)) return true;
//                vis[x]= 0;
//                ans.pop_back();
//            }
//        }return false;
//    }
//};