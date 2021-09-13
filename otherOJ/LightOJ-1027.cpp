/*************************************************************************
	> File Name: LightOJ-1027.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月17日 星期二 10时42分23秒
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

LL gcd(LL a, LL b){
    return b==0 ? a : gcd(b,a%b);
}

int main(){
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int t = 0, num = 0;
        for(int i = 1; i <= n; ++i){
            int x;
            scanf("%d", &x);
            if(x >= 0)
                num++;
            t += abs(x);
        }printf("Case %d: ", ++kase);
        if(!num) puts("inf");
        else printf("%lld/%lld", t / gcd(t, num), num/gcd(t, num));
    }
	return 0;
}
