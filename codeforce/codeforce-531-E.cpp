/*************************************************************************
	> File Name: codeforce-531-E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2019年01月09日 星期三 23时48分58秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 2e5+10;
const LL mod = 998244353;
struct ss{
	int x,y;
	ss(){
		x=y=0;
	}
}a[maxn],b[maxn];

bool cmp(const ss &p, const ss &q){
	if(p.x == q.x) return p.y<q.y;
	return p.x < q.x;
}

map<int, int> ma;

LL qpow(LL x, LL n){
	LL ans = 1;
	while(n){
		if(n&1) ans = ans * x % mod;
		x = x * x % mod;
		n >>= 1;
	}return ans;
}

int main(){
	int n,x;
	scanf("%d", &n);
	int t = 1;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x);
		if(!ma[x]) {
			ma[x] = t++;
			a[ma[x]].x = i;
		}
		a[ma[x]].y = i;
	}
	sort(a+1,a+t,cmp);
	LL ans = 1;
	int r = 1;
	for(int i = 1; i < t; ++i){
		if(a[i].x > r)
			ans = ans * 2 % mod;
		r = max(r, a[i].y);
	}
	printf("%lld\n", ans);
	return 0;
}
