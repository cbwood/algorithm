/*************************************************************************
	> File Name: codeforce548E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年02月28日 星期三 10时44分01秒
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
const int maxn = 2e5 + 10;

int pri[maxn],cnt[maxn], mu[maxn], mark[maxn], a[maxn];
bool vis[maxn];
LL ans;

void Mobius(){
    int num = 0;
    mu[1] = 1;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri[++num] = i;
            mu[i] = -1;
        }for(int j = 1; j <= num && i * pri[j] < maxn; ++j){
            vis[i*pri[j]] = true;
            if(i % pri[j] == 0){
                mu[i*pri[j]] = 0;
                break;
            }mu[i*pri[j]] = -mu[i];
        }
    }
}

void update(int x, int v){
    for(int i = 1; i*i <= x; ++i)
        if(x % i == 0){
            ans -= 1LL * cnt[i] * (cnt[i] - 1) / 2 * mu[i];
            cnt[i] += v;
            ans += 1LL * cnt[i] * (cnt[i] - 1) / 2 * mu[i];
            if(i * i != x){
                int j = x / i;
                ans -= 1LL * cnt[j] * (cnt[j] - 1) / 2 * mu[j];
                cnt[j] += v;
                ans += 1LL * cnt[j] * (cnt[j] - 1) / 2 * mu[j];
            }
        }
}

int main(){
    int n, q;
    Mobius();
    while(scanf("%d %d", &n, &q) != EOF){
        for(int i = 1; i <= n; ++i)
            scanf("%d", a+i);
        ans = 0;
        memset(mark, 0, sizeof(mark));
        while(q--){
            int k;
            scanf("%d", &k);
            mark[k] ^= 1;
            update(a[k], mark[k] ? 1 : -1);
            printf("%lld\n", ans);
        }
    }
	return 0;
}
