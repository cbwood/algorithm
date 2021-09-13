/*************************************************************************
	> File Name: ZOJ-3604.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月18日 星期三 09时05分51秒
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

LL qpow(LL x, LL n){
    LL ans = 1;
    while(n){
        if(n&1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int s, n;
        scanf("%d %d", &n, &s);
        LL ans ;
        if(n == s) ans = 1;
        else ans = qpow(n, n-s-1) * s % mod;
        printf("%lld\n", ans);
    }
	return 0;
}
