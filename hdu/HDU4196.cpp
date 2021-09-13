/*************************************************************************
	> File Name: HDU4196.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年04月21日 星期六 21时58分45秒
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
const int maxn = 1e7 + 10;

vector<int> pri;
bool vis[maxn];
LL fi[maxn];

void init(){
    fi[0] = fi[1] = 1;
    for(int i = 2; i < maxn; ++i){
        fi[i] = fi[i-1];
        if(!vis[i]) pri.emplace_back(i);
        else fi[i] = fi[i] * i % mod;
        for(auto x : pri){
            if(i*x >= maxn) break;
            vis[i*x] = 1;
            if(i%x == 0) break;
        }
    }
}

int main(){
    int n;
    init();
    while(scanf("%d", &n) != EOF && n){
        LL ans = fi[n];
        for(auto x : pri){
            if(x > n/2) break;
            int t = n;
            int num = 0;
            while(t) t /= x, num += t;
            if(num && !(num&1)) ans = ans * x % mod;
        }printf("%lld\n", ans);
    }
	return 0;
}
