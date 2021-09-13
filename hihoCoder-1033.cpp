/*************************************************************************
	> File Name: hihoCoder-1033.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月27日 星期一 21时19分06秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;

int bits[50];
LL dp[30][400][30];
int k;

LL dfs(int pos, int sum, LL x, bool lead, bool limit, int flag, int dept){
	if(pos < 0){
		if(sum - 200 == k){
			return x % mod;
		}return 0;
	}if(!limit&& !lead && dp[pos][sum][dept]!=-1) return dp[pos][sum][dept];
	int up = limit ? bits[pos] : 9;
	LL ans = 0;
	for(int i = 0; i <= up; ++i){
		if(lead){
			if(i == 0) ans += dfs(pos-1, sum, x, lead&&i==0, limit&&i==bits[pos], flag, dept);
			else ans += dfs(pos-1, sum+flag*i, x*10+i, lead&&i==0, limit&&i==bits[pos], -flag, dept+1);
		}else ans += dfs(pos-1, sum+flag*i, (x*10+i)%mod, lead&&i==0, limit&&i==bits[pos], -flag, dept+1);
		ans %= mod;
	}if(!lead&& !limit) dp[pos][sum][dept] = ans;
	return ans;
}

LL solve(LL n){
	int pos = 0;
	while(n){
		bits[pos++] = n % 10;
		n /= 10;
	}LL ans = 0;
	for(int i = pos; i >= 1; --i)
	ans +=  dfs(i-1, 200, 0, 1,1, 1, 0);
	return ans;
}

int main(){
	LL l,r;
	memset(dp, -1, sizeof dp);
	cin >> l >> r >> k;
	LL x = solve(r),y = solve(l-1);
	cout <<( (x-y)%mod+mod)%mod << endl;
}
