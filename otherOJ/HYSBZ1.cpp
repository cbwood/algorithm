/*************************************************************************
	> File Name: HYSBZ1.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年10月08日 星期日 23时02分57秒
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
int cnt, pri[maxn], mu[maxn], sum[maxn];
bool vis[maxn];

void init(){
    cnt = 0;
    mu[1] = 1;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            mu[i] = -1;
            sum[i] = 1;
            pri[++cnt] = i;
        }for(int j = 1; j <= cnt; ++j){
            if(i * pri[j] >= maxn) break;
            vis[i * pri[j]] = true;
            if(i % pri[j]){
                mu[i * pri[j]] = -mu[i];
                sum[i * pri[j]] = mu[i] - sum[i];
            }else {
                mu[i * pri[j]] = 0;
                sum[i * pri[j]] = mu[i];
                break;
            }
        }
    }
}

void solve(int &n){
    LL ans = 0;
    for(int i = 1; i <= n; ++i)
    ans += 1LL * (n/i) * (n/i) * sum[i];
    printf("%lld\n", ans);
}

int main(){
    int n;
    init();
    scanf("%d", &n);
    solve(n);
	return 0;
}
