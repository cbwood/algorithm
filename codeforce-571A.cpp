/*************************************************************************
	> File Name: codeforce-571A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月28日 星期六 09时50分13秒
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

LL solve(int a, int b, int c, int l){
    LL ans = 0;
    for(int i = max(0, b+c-a); i <= l; ++i){
        LL x = min(l-i,a+i-b-c);
        ans += (x+1)*(x+2)/2;
    }return ans;
}

int main(){
    int a,b,c,l;
    scanf("%d %d %d %d",&a, &b, &c, &l);
    LL ans = 0;
    for(int i = 0; i <= l; ++i)
        ans += 1LL*(i+1)*(i+2)/2;
    ans -= solve(a,b,c,l);
    ans -= solve(b,a,c,l);
    ans -= solve(c, a, b, l);
    printf("%lld\n", ans);
	return 0;
}
