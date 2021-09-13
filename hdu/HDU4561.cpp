/*************************************************************************
	> File Name: HDU4561.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年02月07日 星期三 10时07分08秒
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

LL ans[maxn];

LL five(LL n){
    return (3*n*n-n) / 2;
}

void init(){
    ans[0] = 1;
    for(int i = 1; i < maxn; ++i){
        int k = 1;
        for(int j = 1; ;++j){
            int x1 = five(j);
            int x2 = five(-j);
            if(x1 > i && x2 > i) break;
            if(x1 <= i) ans[i] =((ans[i] + k * ans[i-x1]) % mod + mod) % mod;
            if(x2 <= i) ans[i] = ((ans[i] + k * ans[i-x2]) % mod + mod) % mod;
            k *= -1;
        }
    }
}

int main(){
    init();
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        printf("%lld\n",ans[n]);
    }
	return 0;
}
