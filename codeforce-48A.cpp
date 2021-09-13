/*************************************************************************
	> File Name: codeforce-48A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月03日 星期五 22时10分57秒
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
const int maxn = 2e5 + 10;

LL ans[maxn];

int main(){
    int n, m;
    LL tmp = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i){
        LL x;
        scanf("%lld", &x);
        ans[i] = (tmp + x)/m;
        tmp = (tmp + x) % m;
    }for(int i = 1; i<= n; ++i)
        printf("%lld ", ans[i]);
	return 0;
}
