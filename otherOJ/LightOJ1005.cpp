/*************************************************************************
	> File Name: LightOJ1005.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年11月06日 星期一 21时42分57秒
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
const int maxn = 32;

LL c[maxn][maxn];

int main(){
    for(int i = 1; i < maxn; ++i)
        c[i][0] = c[i][i] = 1;
    for(int i = 2; i <= maxn; ++i)
        for(int j = 1; j < i; ++j)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    int t, n, k, kase = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        LL ans = c[n][k] * c[n][k];
        for(int i = 1; i <= k; ++i)
            ans = ans * i;
        if(n < k) ans = 0;
        printf("Case %d: %lld\n", ++kase, ans);
    }
	return 0;
}
