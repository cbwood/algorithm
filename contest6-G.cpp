/*************************************************************************
	> File Name: contest6-G.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月26日 星期二 18时05分02秒
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

LL pqow(LL x, LL n){
    LL ans = 1;
    while(n){
        if(n&1) ans =ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

int main(){
    LL n;
    ios::sync_with_stdio(0);
    cin >> n;
    LL ans = 0;
    n %= mod;
    n = n * 2 % mod;
    ans = n * (n + 1) % mod * pqow(2, mod-2) % mod;
    if(n == 0)
        ans = 1;
    cout << ans << endl;
	return 0;
}
