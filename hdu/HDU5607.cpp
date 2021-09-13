/*************************************************************************
	> File Name: HDU5607.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月17日 星期二 09时09分55秒
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

struct mat{
    LL a[51][51];
    int len;
    mat(){memset(a, 0, sizeof(a));};
    mat operator *(const mat &q){
        mat c;
        for(int i = 1; i <= len; ++i)
            for(int k = 1; k <= len; ++k)
                if(a[i][k])
                    for(int j = 1; j <= len; ++j)
                        c.a[i][j] = (c.a[i][j] + a[i][k] * q.a[k][j]) % mod;
        return c;
    }
};

LL qpow(LL x, LL n){
    LL ans = 1;
    while(n){
        if(n&1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

mat qpow(mat x, LL n){
    mat ans;
    ans.len = x.len;
    for(int i = 0; i <= x.len; ++i)
        ans.a[i][i] = 1;
    while(n){
        if(n&1) ans = ans * x;
        x = x * x;
        n >>= 1;
    }return ans;
}

mat w;
int num[52];

int main(){
    int n, m;
    scanf("%d %d", &n ,&m);
    w.len = n;
    while(m--){
        int x, y;
        scanf("%d %d", &x, &y);
        num[x]++;
        w.a[x][y] = 1;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            w.a[i][j] = w.a[i][j] * qpow(num[i], mod-2);
    int q;
    scanf("%d", &q);
    while(q--){
        int u, k;
        scanf("%d %d", &u, &k);
        mat ans = qpow(w, k);
        for(int i = 1; i <= n; ++i)
            printf("%lld ", ans.a[u][i]);
        printf("\n");
    }
	return 0;
}
