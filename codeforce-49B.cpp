/*************************************************************************
	> File Name: codeforce-49B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月18日 星期六 22时44分48秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
	LL n;
	int q;
	scanf("%lld %d", &n, &q);
	LL t = (n*n+1)/2;
	while(q--){
		int x, y;
		LL ans = 0;
		scanf("%d%d", &x, &y);
		if(n&1){
			if(x&1){
				if(y&1) ans = 1LL*x/2*n+(y+1)/2;
				else ans = t +  1LL*x/2*n + y/2;
			}else {
				if(y&1) ans =t + 1LL* x/2*n-(n-y)/2;
				else ans =  1LL*x/2*n-(n-y)/2;
			}
		}else {
			if((x*1LL+y)&1) ans =t + 1LL* (x-1)*(n/2) + (y+1)/2;
			else ans = 1LL*(x-1)*(n/2) + (y+1)/2;

		}printf("%lld\n" ,ans);
	}return 0;
}
