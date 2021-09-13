/*************************************************************************
	> File Name: HDU1796.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月28日 星期六 10时09分10秒
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

int a[20];

LL gcd(LL a, LL b){
    return b ? gcd(b,a%b) : a;
}

LL lcm(LL a, LL b){
    return a/gcd(abs(a),abs(b))*b;
}

int main(){
    int m;
    LL n;
    while(scanf("%lld %d", &n, &m)!=EOF){
    int k = 0;
    for(int i = 0; i < m; ++i){
        int x;
        scanf("%d", &x);
        if(x) a[k++] = x;
    } 
    LL ans = 0;
        m = k;
    n--;
    for(int i = 1; i < (1 << m); ++i){
        LL lm = 1;
        int s = 0;
        for(int j = 0; j < m; ++j)
        if(i&(1<<j)){
            s++;
             lm = lcm(lm, a[j]);
        }if(s&1) ans += n/lm;
        else ans -= n/lm;
    }printf("%lld\n", ans);}
	return 0;
}
