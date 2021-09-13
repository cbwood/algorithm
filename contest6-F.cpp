/*************************************************************************
	> File Name: contest6-F.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月26日 星期二 20时14分32秒
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

int a[maxn], b[maxn];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n; ++i){
        int x;
        scanf("%d", &x);
        a[x] = i;
    }for(int i = 1; i <= n; ++i){
        int x;
        scanf("%d", &b[i]);
    }int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(a[b[i]] < i)
            ans = max(ans, i - a[b[i]]);
    }printf("%d\n", ans);
	return 0;
}
