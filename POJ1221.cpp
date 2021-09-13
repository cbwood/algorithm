/*************************************************************************
	> File Name: POJ1221.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年02月07日 星期三 17时10分05秒
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

int a[maxn], b[maxn];

int solve(int m, int n){
    if(m == 0)
        m = n;
    memset(a, 0, sizeof(a));
    for(int i = 0; i <= n; ++i)
        a[i] = 1;
    for(int i = 2; i <= m; ++i){
        for(int j = 0; j <= n; ++j)
            for(int k = 0; k +j <= n; k += i)
                b[j+k] += a[j];
        for(int j = 0; j <= n; ++j)
            a[j] = b[j], b[j] = 0;
    }return a[n];
}

int main(){
    int n;
    while(scanf("%d", &n) && n){
        LL ans = 0;
        for(int i = 0; i <= n; ++i)
            if((n-i)%2 == 0)
                ans += solve(i, (n-i)/2);
        printf("%d %lld\n",n, ans);
    }
	return 0;
}
