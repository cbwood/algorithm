/*************************************************************************
	> File Name: HDU-6410.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月22日 星期三 09时54分29秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;
const int maxn = 1e4 + 10;
#define fi first
#define se second
#define pb push_back
#define mp make_pair

vector<pair<int, int> > v;

LL qpow(LL x, LL n){
    LL ans = 1;
    x = x % mod;
    while(n){
        if(n&1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

inline int cal(LL x, LL y){
	if(y < x) return 0;
	return (x+y)*(y-x+1)/2;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d", &n);
		v.clear();
		int l = 0,r = 0;
		LL w = 1;
		for(int i = 1; i <= n; ++i){
			int x,y;
			scanf("%d%d", &x, &y);
			w = w * (y-x+1) % mod;
			l = max(l, x);
			r = max(r, y);
			v.pb(mp(x,y));
		}
		LL ans = 0;
		LL pre = 0, now = 0;
		for(int i = l; i <= r; ++i){
			now = 1;
			for(auto &y: v){
				int x = min(y.se, i);
				now = now* cal(i-x + 1,i-y.fi+1) % mod;
			}
			pre = 1;
			for(auto &y : v){
				int x = min(y.se, i-1);
				pre = pre * cal(i-x+1, i-y.fi+1) % mod;
			}
			ans = (ans + now - pre + mod) % mod;
		}printf("%lld\n", ans * qpow(w, mod-2) % mod);
	}return 0;
}
