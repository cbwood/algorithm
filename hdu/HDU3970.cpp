/*************************************************************************
	> File Name: HDU3970.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年04月20日 星期五 21时08分12秒
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
const int maxn = 1e5 + 10;

vector<int> fac, pri;
bool vis[maxn];

void init(){
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]) pri.emplace_back(i);
        for(auto x : pri){
            if(x*i > maxn) break;
            vis[i*x] = 1;
            if(i % x == 0) break;
        }
    }
}

void getfac(int n){
    fac.clear();
    for(int i = 1; i <= sqrt(n+0.5); i ++)
        if(n % i == 0){
            if(i&1) fac.emplace_back(i);
            if(((n/i)&1) && i * i != n)  
                fac.emplace_back(n/i);
        }
}

LL qpow(LL x, LL n){
    LL ans = 1;
    x %= mod;
    while(n){
        if(n&1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

int phi(int n){
    int ans = n;
    int m = n;
    for(auto x : pri){
        if(1LL * x*x > 1LL * n) break;
        if(n % x == 0){
            ans -= ans/x;
            while(n%x == 0)
                n /= x;
        }
    }if(n > 1) ans -= ans/n;
    return ans;
}

int main(){
    int t;
    init();
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        getfac(n);
        LL ans = 0;
        for(auto x : fac)
            ans = (ans + qpow(2, n/x)* phi(x)) % mod;
        ans = ans * qpow(n, mod-2) % mod;
        printf("%lld\n", ans);
    }
	return 0;
}
