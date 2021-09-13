/*************************************************************************
	> File Name: UVA-11426.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月01日 星期三 09时16分12秒
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
#define sqr(x) (x)*(x)
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const LL mod = 1e9 + 7;
const int maxn = 4e6 + 10;

int pri[maxn], mu[maxn], sum[maxn];
bool vis[maxn];
int cnt;

void Mobius(){
    cnt = 0;
    mu[1] = sum[1] = 1;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri[++cnt] = i;
            mu[i] = -1;
        }for(int j = 1; j <= cnt && i * pri[j] < maxn ;++j){
            vis[i*pri[j]] = 1;
            if(i % pri[j] == 0){
                mu[i*pri[j]] == 0;
                break;
            }mu[i*pri[j]]= -mu[i];
        }sum[i] = sum[i-1] + mu[i];
    }
}

int main(){
    Mobius();
    int n;
    while(scanf("%d", &n) != EOF && n){
        LL ans = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = i; j <= n; j += i)
                ans += 1LL * i * (n/j) * (n/j)* mu[j/i];
            ans -= i;
        }printf("%lld\n", ans/2);
    }
	return 0;
}
