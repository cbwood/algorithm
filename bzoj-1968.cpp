/*************************************************************************
	> File Name: bzoj-1968.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月03日 星期五 16时19分20秒
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
    int n;
    scanf("%d", &n);
    LL ans = 0;
    for(int i = 1,j; i <= n; i = j +1){
        j = (n/(n/i));
        ans += (j-i+1) * (n/i);
    }printf("%lld\n",ans);
	return 0;
}
