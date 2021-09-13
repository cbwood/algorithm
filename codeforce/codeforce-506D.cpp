/*************************************************************************
	> File Name: codeforce-506D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月24日 星期五 23时49分15秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 2e5 + 10;

int a[maxn];
LL pow1[15];
map<int, int> cnt[15];

int dig(LL x){
	int num = 0;
	while(x){
		x /= 10;
		num++;
	}return num;
}

int main(){
	int n,k;
	pow1[0] = 1;
	for(int i = 1; i < 15; ++i)
		pow1[i] = pow1[i-1] * 10;
	scanf("%d%d", &n,&k);
	LL x;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		x = a[i] % k;
		for(int j = 1; j <= 10; ++j){
			x *= 10;
			x %= k;
			cnt[j][x]++;
		}
	}
	LL ans = 0;
	for(int i = 1; i <= n; ++i){
		LL x = a[i];
		int num = dig(x);
		x %= k;
		ans += cnt[num][(k-x+k)%k];
		x = x * pow1[num] % k;
		x = (x+a[i])%k;
		if(x == 0) ans--;
	}printf("%lld\n", ans);
	return 0;
}
