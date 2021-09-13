/*************************************************************************
	> File Name: HDU5942.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年04月13日 星期五 11时27分29秒
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
const int maxn = 1e6 + 10;

int mu[maxn];
LL s[maxn];
vector<int> pri;
bool vis[maxn];

void Mobius(){
    mu[1] = 1;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            pri.emplace_back(i);
            mu[i] = -1;
        }
        for(auto x : pri){
            if(x*i > maxn) break;
            vis[x*i] = true;
            if(i % x == 0){
                mu[i*x] = 0;
                break;
            }mu[i*x] = -mu[i];
        }
    }
}

LL solve(LL n){
    if(n < maxn&& s[n] != -1) return s[n];
    LL ans = 0, i, pre;
    for(i = 1; i*i <= n; i++){
        ans += (n/i);
    }
    for(LL t = n / i; i <= n; i = pre+1,t--)
        pre = n/t, ans = (ans + (pre-i+1)*t) % mod;
    ans = (ans % mod + mod) % mod;
    if(n < maxn) s[n] = ans;
    return ans;
}

int main(){
    Mobius();
    int t, kase = 0;
    memset(s, -1, sizeof(s));
    scanf("%d", &t);
    while(t--){
        LL n;
        scanf("%lld", &n);
        LL ans = 0;
        for(int i = 1; 1LL * i*i<= n; ++i)
            if(mu[i]){
                ans += mu[i] == 1 ? solve(n/i/i) : mod - solve(n/i/i);
                if(ans >= mod) ans -= mod;
            }
        printf("Case #%d: %lld\n", ++kase, (ans % mod+mod) % mod);
    }
	return 0;
}
