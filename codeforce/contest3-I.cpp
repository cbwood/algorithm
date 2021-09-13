/*************************************************************************
	> File Name: contest3-I.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年10月29日 星期日 19时47分34秒
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
const int mod = 1e9 + 9;
const int maxn = 1e5 + 10;

LL qpow(LL x, LL n){
    x %= mod;
    LL ans = 1;
    while(n){
        if(n&1) ans  = ans * x % mod;
        n >>= 1;
        x = x * x % mod;
    }return ans;
}

int main(){
    LL n, k, m;
    scanf("%lld %lld %lld", &n, &m, &k);
    LL ans = 0;
    LL res = n - m;
    if(res * (k - 1) >= m) {
        printf("%lld\n",  m % mod);
        return 0;
    }
    LL t = m - res * (k - 1);
    LL num = t / k;
    ans = (qpow(2, num + 1) - 2) * k % mod;
    ans += t - num * k + res * (k - 1);
    ans =(ans % mod + mod) % mod;
    printf("%lld\n", ans);
	return 0;
}
