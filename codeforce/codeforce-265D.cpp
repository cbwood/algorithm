/*************************************************************************
	> File Name: codeforce-265D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月24日 星期二 19时36分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<string>

using namespace std;
const int maxn = 1e5 + 10;

vector<int > a[maxn], pri;
bool vis[maxn];
int dp[maxn];
int num;

void init(){
    num = 0;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]) pri.emplace_back(i);
        for(auto x : pri){
            if(x * i >= maxn) break;
            vis[x*i] = 1;
            if(x % i == 0) break;
        }
    }
    for(int i = 1; i < maxn; ++i){
        int j = i;
        for(auto x : pri){
            if(x > j) break;
            if(j % x == 0){
                a[i].emplace_back(x);
                    while(j % x == 0) j /= x;
            }
        }
        if(j > 1) a[i].emplace_back(j);
    }
    a[1].emplace_back(1);
}

int main(){
    init();
    int n, tmp;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int x;
        tmp = 1;
        scanf("%d", &x);
        if(x == a[x][0])
            dp[x] = 1;
        else {
            for(auto t : a[x])
                tmp = max(tmp, dp[t]+1);
        }
        for(auto t : a[x])
            dp[t] = tmp;
        ans = max(ans, tmp);
    }printf("%d\n",ans);
	return 0;
}
