/*************************************************************************
	> File Name: codeforce-49E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月19日 星期日 00时20分04秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 998244353;

LL qpow(LL x, LL n){
    LL ans = 1;
    x = x % mod;
    while(n){
        if(n&1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

int main(){
	LL ans  = 0;
	int n,k;
	scanf("%d%d", &n,&k);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(i*j >= k){
				ans = (ans + max(qpow(2,i+j-1)-2,0LL)) % mod;
			}
	printf("%lld\n", ans);
	return 0;
}
