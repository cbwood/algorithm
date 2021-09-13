/*************************************************************************
	> File Name: SGU-275.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月07日 星期二 10时58分46秒
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
const int MAX_BASE = 62;

LL a[110],b[110];

LL solve(int n) {
    for (int i = 0; i < n; ++i)
        for (int j = MAX_BASE; j >= 0; --j)
            if (a[i] >> j & 1) {
                if (b[j]) a[i] ^= b[j];
                else {
                    b[j] = a[i];
                    for (int k = j - 1; k >= 0; --k)
                        if (b[k] && (b[j] >> k & 1))
                            b[j] ^= b[k];
                    for (int k = j + 1; k <= MAX_BASE; ++k)
                        if (b[k] >> j & 1)
                            b[k] ^= b[j];
                    break;
                }
            }
    LL ans = 0;
    for(int i = 0; i <= MAX_BASE; ++i)
        ans ^= b[i];
    return ans;
}


int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%lld",a+i);
    printf("%lld\n",solve(n));
	return 0;
}
