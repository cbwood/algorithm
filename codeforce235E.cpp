/*************************************************************************
	> File Name: codeforce235E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年03月20日 星期二 09时38分36秒
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
const int mod = 1<<30;
const int maxn = 2e3+10;

int mu[maxn], pri[maxn];
int gcd[maxn][maxn];
bool vis[maxn];

void init(){
    mu[1] = 1;
    int cnt = 0;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri[++cnt] = i;
            mu[i] = -1;
        }for(int j = 1; j <= cnt && i * pri[j] < maxn; ++j){
            vis[i*pri[j]] = true;
            if(i%pri[j] == 0){
                mu[i*pri[j]] = 0;
                break;
            }mu[i*pri[j]] = -mu[i];
        }
    }for(int i = 0; i < maxn; ++i)
        gcd[i][0] = gcd[0][i] = i;
    for(int i = 1; i < maxn; ++i)
        for(int j = 1; j <= i; ++j)
            gcd[i][j] = gcd[j][i] = gcd[j][i%j];
}

LL solve(int n, int d, int i){
    LL sum = 0;
    for(int j = 1; j <= n; ++j){
        if(gcd[i][j*d] == 1) sum = (sum + n/j) % mod;
    }return sum;
}

int main(){
    init();
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        LL ans = 0;
        for(int i = 1; i <= a; ++i){
            LL num = 0;
            for(int j = 1; j <= min(b, c); ++j){
                num += (1LL * mu[j] * solve(b/j,j,i)*solve(c/j, j, i) % mod + mod) % mod;
                num %= mod;
            }
            ans = (ans + (1LL*a/i)* num) % mod;
        }printf("%lld\n", ans);
    }
	return 0;
}
