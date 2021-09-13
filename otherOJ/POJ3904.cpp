/*************************************************************************
	> File Name: POJ3904.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年02月14日 星期三 19时31分30秒
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
const int maxn = 1e4 + 10;

int pri[maxn], mu[maxn],num[maxn];
bool vis[maxn];

void Mobius(){
    int cnt = 0;
    mu[1] = 1;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri[++cnt] = i;
            mu[i] = -1;
        }for(int j = 1; j <= cnt && i * pri[j] < maxn; ++j){
            vis[i*pri[j]] = true;
            if(i % pri[j] == 0){
                mu[i*pri[j]] = 0;
                break;
            }mu[i*pri[j]] = - mu[i];
        }
    }
}

LL Getc(LL n){
    return n * (n-1) * (n-2) * (n-3) / 24;
}

void add(int n){
    int t = sqrt(n*1.0);
    for(int i = 1; i <= t; ++i)
        if(n%i == 0){
            num[i]++;
            num[n/i]++;
        }
    if(t*t == n)
        num[t]--;
}

int main(){
    int n;
    Mobius();
    while(scanf("%d", &n) != EOF){
        memset(num, 0, sizeof(num));
        for(int i = 1;i <= n; ++i){
            int x;
            scanf("%d", &x);
            add(x);
        }
        LL ans = 0;
        for(int i = 1; i < maxn; ++i)
            if(num[i] >= 4 && mu[i])
                ans += Getc(num[i]) * mu[i];
        printf("%lld\n", ans);
    }
	return 0;
}
