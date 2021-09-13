/*************************************************************************
	> File Name: HDU1695.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月31日 星期二 20时11分40秒
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
const int maxn = 1e5 + 10;

int pri[maxn], mu[maxn];
bool vis[maxn];

void Mobius(){
    int num = 0;
    mu[1] = 1;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri[++num] = i;
            mu[i] = -1;
        }for(int j = 1; j <= num ; ++j){
            if(i*pri[j] >= maxn) break;
            vis[i*pri[j]] = 1;
            if(i % pri[j] == 0){
                mu[i*pri[j]] = 0;
                break;
            }mu[i*pri[j]] = -mu[i];
        }
    }
}

/*
int cnt;

void Mobius(){
    cnt = 0;
    mu[1] = 1;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri[++cnt] = i;
            mu[i] = -1;
        }for(int j = 1; j <= cnt; ++j){
            if(i * pri[j] >= maxn) break;
            vis[i * pri[j]] = true;
            if(i % pri[j] == 0){
                mu[i * pri[j]] = 0;
                break;
            }mu[i * pri[j]] = -mu[i];
        }
    }
}
*/
int main(){
    int a,b,c,d,k;
    int t, kase = 0;
    Mobius();
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        if(k == 0) {
            printf("Case %d: 0\n", ++kase);
            continue;
        }
        b /= k;
        d /= k;
        if(b > d) swap(b,d);
        LL ans = 0, tmp = 0;
        for(int i = 1; i <= b; ++i)
            ans += 1LL* (b/i) * (d/i) * mu[i];
        for(int i = 1; i <= b; ++i)
            tmp += 1LL * (b/i) * (b/i) * mu[i];
        printf("Case %d: %lld\n",++kase, ans - tmp/2);
    }
	return 0;
}
