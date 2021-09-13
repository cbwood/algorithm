/*************************************************************************
	> File Name: HYSBZ2818.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年10月05日 星期四 22时33分38秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define sqr(x) ((x)*(x))
using namespace std;

typedef long long LL;
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxt = 1e7 + 10;

int pri[maxt];
bool vis[maxt];
int mu[maxt], sum[maxt];
int cnt;

void init(){
    cnt = 0;
    mu[1] = 1;
    for(int i = 2; i < maxt; ++i){
        if(!vis[i]){
            mu[i]= -1;
            sum[i] = 1;
            pri[++cnt] = i;
        }for(int j = 1; j <= cnt; ++j){
            if(i * pri[j] > maxt) break;
            vis[i * pri[j]] = true;
            if(i % pri[j]){
                mu[i * pri[j]] = - mu[i];
                sum[i * pri[j]] = mu[i] - sum[i];
            }else {
                mu[i * pri[j]] = 0;
                sum[i * pri[j]] = mu[i];
                break;
            }
        }
     }   
}

void solve(int n){
    LL ans = 0;
    for(int i = 2; i <= n; ++i)
        ans += 1LL * n / i * n / i * sum[i];
    printf("%lld\n" ,ans);
}

int main(){
    int n;
    init();
    scanf("%d", &n);
    solve(n);
    return  0;
}
