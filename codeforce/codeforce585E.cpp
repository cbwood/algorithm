/*************************************************************************
	> File Name: codeforce585E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年03月02日 星期五 22时28分30秒
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

int pri[maxn], mu[maxn], num[maxn], fi[maxn];
bool vis[maxn];

void Mobius(){
    int cnt = 0;
    mu[1] = 1;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri[++cnt] = i;
            mu[i] = -1;
        }for(int j = 1; j <= cnt && i*pri[j] < maxn; ++j){
            vis[i*pri[j]] = true;
            if(i % pri[j] == 0){
                mu[i*pri[j]] = 0;
                break;
            }mu[i*pri[j]] = -mu[i];
        }
    }
    fi[0] = 1;
    for(int i = 1; i < maxn; ++i)
        fi[i] = fi[i-1] * 2 % mod;
}

int main(){
    int n;
    Mobius();
    while(scanf("%d", &n) != EOF){
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= n; ++i){
            int x;
            scanf("%d", &x);
            num[x]++;
        }
        LL ans = 0;
        for(int i = 2; i <= maxn - 10; ++i)
            if(mu[i]){
                int k = 0;
                for(int j = i; j <= maxn-10; j += i)
                    k += num[j];
                LL t = (n-k) * 1LL * (fi[k] - 1);
                ans = (ans - mu[i] * t) % mod;
            }
        ans = (ans % mod + mod ) % mod;
        printf("%lld\n", ans);
    }
	return 0;
}
