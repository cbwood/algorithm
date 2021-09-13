/*************************************************************************
	> File Name: HDU-4814.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年10月03日 星期三 14时33分40秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 200;
int a[maxn];

int main(){
	LL n;
	while(scanf("%lld", &n) != EOF){
		bool flag = true;
		memset(a, 0, sizeof(a));
		a[50] = n;
		while(flag){
			flag = false;
			for(int i = 0; i <= 100; ++i)
				if(a[i] && a[i+1]){
					LL tmp = min(a[i],a[i+1]);
					a[i] -= tmp;
					a[i+1] -= tmp;
					a[i+2] += tmp;
					flag = true;
				}
			for(int i = 2; i <= 100; ++i)
				if(a[i] > 1){
					LL tmp = a[i]/2;
					a[i+1] += tmp;
					a[i-2] += tmp;
					a[i] =a[i]&1;
					flag = true;
				}
		}
		int st,ed;
		for(int i = 0; i <= 100; ++i)
			if(a[i]){
				st = i;
				break;
			}
		for(int j = 199; j >= 0; --j)
			if(a[j]){
				ed = j;break;
			}
		for(int i = ed; i >= st; --i){
			if(i == 49) printf(".");
			printf("%lld", a[i]);
		}printf("\n");
	}return 0;
}
