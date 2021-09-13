/*************************************************************************
	> File Name: bzoj-2154.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月02日 星期四 10时30分53秒
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
const int mod = 20101009;
const int maxnn = 1e7 + 10;
int maxn;
int mu[maxnn],pri[maxnn], sum[maxnn];
bool vis[maxnn];
int cnt;

template <class T>
inline bool scan_d(T &ret) {
    char c; int sgn;
    if(c = getchar(),c == EOF) return 0; //EOF
    while(c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c-'0');
    while(c = getchar(),c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
inline void out(int x) {
	if(x > 9) out( x / 10);
	putchar( x % 10 + '0');
}

void init(){
    sum[1] = mu[1] = 1;
    cnt = 0;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri[++cnt] = i;
            mu[i] = -1; 
        }for(int j = 1; j <= cnt; ++j){
            if(i*pri[j] >= maxn) break;
            vis[i*pri[j]] = 1;
            if(i % pri[j] == 0){
                mu[i*pri[j]] = 0;
                break;
            }mu[i*pri[j]] = -mu[i];
        }sum[i] = (sum[i-1] + 1LL*i*i*mu[i])%mod;
        sum[i] = (sum[i] + mod)% mod;
    }
}

inline int cal(int x, int y){
    return (1LL * x*(x+1)/2 % mod) * (1LL * y *(y+1) /2%mod) % mod;
}

inline int solve(int n, int m){
    int ans = 0;
    for(int i = 1, j; i <= n; i=j+1){
        j = min(n/(n/i),m/(m/i));
        ans = (ans +1LL* (sum[j] - sum[i-1]) * cal(m/i,n/i) )% mod;
    }return (ans+mod)%mod;
}

int main(){
    int n, m;
    scan_d(n);
        scan_d(m);
        LL ans = 0;
        int tt;
        if(n > m) swap(n,m);
    maxn = n+10;
    init();
        for(int i = 1, j; i <= n; i = j+1){
            j = min((n/(n/i)), m / (m/i));
            ans = (ans +(i +j) *1LL* (j -i+1)/2 % mod * solve(n/i,m/i)) % mod;
        }out(ans);
    return 0;
}
