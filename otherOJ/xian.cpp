/*************************************************************************
	> File Name: contest3-E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年10月29日 星期日 18时05分30秒
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
const int maxn = 1e7 + 10;
bool vis[maxn];
int num[maxn];
int pri[maxn];

LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}


int main(){
    LL a, b, c, d;
    while(scanf("%lld %lld %lld %lld", &a, &b, &c, &d) != EOF){
            LL x = a + c, y = b + d;
            bool check = true;
            LL prex, prey ;
            prex = prey = 0;
            while(check){
                if(b * x <= a * y)
                    y--, check = false;
                else if(x * d >= c * y)
                    x--, check = false;
                check != check;
                if(x == prex && y == prey)
                    check = false;
                prex = x;
                prey = y;
            }
            printf("%lld/%lld\n",x/gcd(x,y), y/gcd(x,y));
    }
}
