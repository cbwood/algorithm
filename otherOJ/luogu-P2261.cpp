/*************************************************************************
	> File Name: luogu-P2261.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月31日 星期二 21时07分52秒
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
const LL mod = 1e9 + 7;
const int maxn = 1e5 + 10;

int main(){
    LL n, k;
    scanf("%lld %lld", &n ,&k);
    LL ans = n*k;
    for(int i = 1, j; i <= n; i = j+1){
        if(k/i) j = min(k/(k/i),n);
        else j = n;
        ans -= (k/i)*(i+j)*(j-i+1)/2;
    }printf("%lld\n", ans);
	return 0;
}
