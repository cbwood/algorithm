/*************************************************************************
	> File Name: BZOJ2154.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年03月06日 星期二 22时09分50秒
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
const int mod = 20101009;
const int maxn = 1e7 + 10;

int pri[maxn], mu[maxn];
LL sum[maxn];
bool vis[maxn];

void Mobius(){
    int cnt = 0;
    mu[1] = 1;
    sum[1] = 1;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri[++cnt] = i;
            mu[i] = -1;
        }for(int j = 1; j <= cnt && i * pri[j] < maxn; ++j){
            vis[i*pri[j]] = true;
            if(i % pri[j] == 0){
                mu[i*pri[j]] = 0;
                break;
            }mu[i*pri[j]] = -mu[i];
        }
        sum[i] = (sum[i-1] + 1LL * i*i*mu[i]) % mod;
        sum[i] = (sum[i] + mod) % mod;
    }
}

LL cal(int x, int y){
    return (1LL * x * (x+1)/2 % mod) * (1LL * y * (y+1)/2 % mod) % mod;
}

LL F(int x, int y){
    LL ans = 0;
    int t = min(x, y);
    for(int i = 1, last; i <= t; i = last + 1){
        last = min(x/(x/i), y/(y/i));
        ans = (ans + (sum[last] - sum[i-1])* cal(x/i, y/i) % mod + mod) % mod;
    }
    return (ans + mod) % mod;
}


int main(){
    int n, m;
    Mobius();
    while(scanf("%d %d", &n, &m) != EOF){
        LL ans = 0;
        int t = min(n, m);
        for(int i = 1, last = 0; i <= t; i = last + 1){
            last = min(m / (m/i), n/ (n/i));
            ans = (ans + (i+last) *1LL * (1 + last-i ) / 2% mod * F(n/i,m/i)) % mod;
        }
        printf("%lld\n", ans);
    }
	return 0;
}
