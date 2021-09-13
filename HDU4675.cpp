/*************************************************************************
	> File Name: HDU4675.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年02月12日 星期一 21时32分00秒
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
const int maxn = 3e5 + 10;

int mu[maxn], pri[maxn], num[maxn];
LL f[maxn], inv[maxn], F[maxn];
bool vis[maxn];

void Mobius(){
    int cnt = 0;
    mu[1] = 1;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri[++cnt] = i;
            mu[i] = -1;
        }
        for(int j = 1; j <= cnt && i * pri[j] < maxn; ++j){
            vis[i*pri[j]] = true;
            if(i%pri[j] == 0){
                mu[i*pri[j]] = 0;
                break;
            }else mu[i*pri[j]] = -mu[i];
        }
    }
}

LL qpow(LL x, LL n){
    LL ans = 1;
    while(n){
        if(n&1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

void init(){
    Mobius();
    f[0] = f[1] = 1;
    inv[0] = inv[1] = 1;
    for(int i = 2; i < maxn; ++i){
        f[i] = f[i-1] * i % mod;
        inv[i] = qpow(f[i], mod-2);
    }
}

int main(){
    int n, m, k;
    init();
    while(scanf("%d %d %d", &n, &m, &k) != EOF){
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= n; ++i){
            int x;
            scanf("%d", &x);
            num[x]++;
        }for(int i = 1; i <= m; ++i)
            for(int j = i * 2; j <= m; j += i)
                num[i] += num[j];
        LL ans = 0;
        for(int i = 1; i <= m; ++i){
            if(num[i] < n - k){
                F[i] = 0;
                continue;
            }
            LL tmp = inv[n-k] * inv[num[i]+k-n] % mod;
            tmp = tmp * f[num[i]] % mod;
            F[i] = tmp * qpow(m/i - 1, num[i]+k-n) % mod * qpow(m/i, n - num[i]) % mod;
        }
        for(int i = 1; i <= m; ++i){
            ans = 0;
            for(int j = i; j <= m; j += i)
                ans = (ans + mu[j/i] * F[j]) % mod;
            printf("%lld", (ans+mod)% mod);
            if(i != m)
                printf(" ");
            else puts("");
        }
    }
	return 0;
}
