/*************************************************************************
	> File Name: codeforce-505B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月19日 星期日 21时47分04秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

typedef  long long LL;

LL a[150009], b[150009];
vector<int> fac;

void solve(LL n){
	for(int i = 2; i <= sqrt(n*1.0); ++i){
		if(n% i == 0){
			fac.emplace_back(i);
			while(n % i == 0) n /= i;
		}
	}if(n > 1) fac.emplace_back(n);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%lld %lld", &a[i], &b[i]);
	}
	solve(a[1]);
	solve(b[1]);

	int sz = fac.size();
	LL ans = -1;
	for(int i = 0; i < sz; ++i){
		bool check = true;
		for(int j = 2; j <= n; ++j)
			if(a[j] % fac[i] && b[j] % fac[i]){
				check = false;
				break;
			}if(check){
				ans = fac[i];
				break;
			}
	}printf("%lld\n", ans);
}
