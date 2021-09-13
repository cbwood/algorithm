/*************************************************************************
    > File Name: HDU3823.cpp
    > Author: wood
    > Mail: cbcruel@gmail.com
    > Created Time: 2018年04月21日 星期六 09时47分42秒
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
typedef long long LL;
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 2e7;

vector<int> pri;
bool vis[maxn];
bool check[200];

void init(){
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]) pri.emplace_back(i);
        for(auto x : pri){
            if(1LL*x*i >= maxn) break;
            vis[i*x] = 1;
            if(i % x == 0) break;
        }
    }for(int i = 1; i < pri.size(); ++i){
        if(pri[i] - pri[i-1] > 150) continue;
            check[pri[i]-pri[i-1]] = 1;
    }
}

int main(){
    int t, kase = 0;
    init();
    scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a > b) swap(a, b);
        printf("Case %d: ", ++kase);
        int d = b-a;
        if(!check[d])
            printf("-1\n");
        else {
            int ans = -1;
            if(a == b){
                ans = *lower_bound(pri.begin(),pri.end(), a) - a;
            }else 
            for(int i = 1; i < pri.size(); ++i)
                if(pri[i] - pri[i-1] == d && a <= pri[i-1]){
                    ans = pri[i-1]-a;
                    break;
                }
            printf("%d\n", ans);
        }
    }
    return 0;
}
