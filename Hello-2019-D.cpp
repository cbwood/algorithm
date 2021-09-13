/*************************************************************************
	> File Name: Hello-2019-D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2019年01月05日 星期六 16时01分01秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 1e9+7;
const int maxn = 100;

LL inv[maxn];

LL qpow(LL x, LL n){
	LL ans = 1;
	while(n){
		if(n&1) ans = ans * x % mod;
		x = x * x % mod;
		n >>= 1;
	}return ans;
}

LL dp[maxn*maxn+10][maxn];

LL solve(LL x, int k, int m){
	memset(dp, 0, sizeof(dp));
	dp[0][m] = 1;
	for(int i = 1; i <= k; ++i)
		for(int j = 0; j <= m; ++j)
			if(dp[i-1][j]){
				for(int l = 0; l <= j; ++l) dp[i][l] = (dp[i][l] + dp[i-1][j] * inv[j+1] % mod) % mod;
			}
	LL ans = 0, res = 1;
	for(int i = 0; i <= m; ++i){
		ans = (ans + res * dp[k][i] % mod) % mod;
		res = res * x % mod;
	}return ans;
}

int main(){
	LL n;
	int k;
	inv[1] = 1;
	for(int i = 2; i < maxn; ++i) inv[i] = (mod-mod/i)*inv[mod%i] % mod;
	cin >> n >> k;
	LL ans = 1;
	for(LL x = 2; x * x <= n; ++x)if(n%x == 0){
		int num = 0;
		while(n%x == 0) num++, n /= x;
		ans = ans * solve(x, k, num) % mod;
	}if(n > 1) ans = ans * solve(n, k, 1) % mod;
	cout << ans << endl;
	return 0;
}
