/*************************************************************************
	> File Name: HDU-6428.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月27日 星期一 16时24分10秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 1LL<<30;
const int  maxn = 1e7 + 10;

int h[maxn],f[2][maxn];
int pri[maxn/10];
bool vis[maxn];
int cnt;

void init(){
	cnt = 0;
	h[1] = f[0][1] = f[1][1] = 1;
	for(int i = 2; i < maxn; ++i){
		if(!vis[i]){
			pri[++cnt] = i;
			h[i] = i-2;
			f[0][i] = i;
			f[1][i] = i;
		}for(int j = 1; j <= cnt; ++j){
			int u = i * pri[j];
			if(u >= maxn) break;
			vis[u] = 1;
			if(i % pri[j] == 0){
				int tmp = u;
				int num = 0;
				while(tmp % pri[j] == 0 && num <= 3) tmp /= pri[j], num++;

				if(num == 1) f[0][u] = f[0][i] * pri[j], f[1][u] = f[1][i] * pri[j];
				else f[0][u] = f[0][i/pri[j]] * pri[j];

				if(num == 2) f[1][u] = f[1][i/pri[j]] * pri[j];
				else if(num >= 3) f[1][u] = f[1][i/pri[j]/pri[j]] * pri[j];

				if(num == 1)
					h[u] = h[i] * (pri[j] - 2);
				else if(num == 2) h[u] = h[i/pri[j]] * (pri[j]-1) * (pri[j] - 1);
				else h[u] = h[i] * pri[j];

				break;
			}f[0][u] = f[0][i] * pri[j];
			f[1][u] = f[1][i] * pri[j];
			h[u] = h[i] * (pri[j]-2);
		}
	}
}

int main(){
	init();
	int t;scanf("%d", &t);
	while(t--){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		LL ans = 0;
		for(int i = 1; i <= a; ++i){
			ans =(ans +1LL*h[i] * (a/i) % mod * (b/f[0][i]) % mod * (c/f[1][i]) % mod) % mod;
		}printf("%lld\n", ans);
	}return 0;
}
