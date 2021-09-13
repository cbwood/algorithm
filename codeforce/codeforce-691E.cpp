/*************************************************************************
	> File Name: codeforce-691E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月19日 星期日 19时31分34秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;

struct mat{
	int n,m;
    LL a[102][102];
    mat (){memset(a, 0, sizeof(a)); }
    mat operator *(const mat &q){
        mat c;
		c.n = c.m = n;
        for(int i = 1; i <= n; ++i)
            for(int  k = 1; k <= m; ++k)
            if (a[i][k])
        for(int j = 1; j <= q.m; ++j){
            c.a[i][j] += a[i][k] * q.a[k][j];
            c.a[i][j] = (c.a[i][j] % mod + mod) % mod;
        }return c;
    }
};

mat qpow(mat x, LL n){
    mat ans;
	ans.n = ans.m = x.n;
    for(int i = 1; i <= ans.n; ++i)
        ans.a[i][i] = 1;
    while(n){
        if (n&1) ans = ans * x;
        x = x * x;
        n >>= 1;
    }return ans;
}

LL qpow(LL x, LL n){
    LL ans = 1;
    x = x % mod;
    while(n){
        if(n&1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

LL w[110];

int solve(LL n){
	int num = 0;
	while(n){
		if(n&1) num++;
		n >>= 1;
	}return num%3;
}

void debug(mat t){
	for(int i = 1; i <= t.n; ++i){
		for(int j = 1; j <= t.m; ++j)
			printf("%lld ",t.a[i][j]);
		printf("\n");
	}
}

int main(){
	mat t;
	int n;
	LL k;
	scanf("%d %lld", &n,&k);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &w[i]);
	t.n = t.m = n;
	for(int i = 1; i <=n; ++i)
		for(int j = 1; j <= n; ++j)
			t.a[i][j] = (solve(w[i]^w[j]) ? 0 : 1);
	if(k == 1){
		printf("%d\n", n);
		return 0;
	}
	mat ans = qpow(t, k-1);
	LL num = 0;
	ans.n = ans.m = n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			(num += ans.a[i][j]) %= mod;
	printf("%lld\n", num);
}
