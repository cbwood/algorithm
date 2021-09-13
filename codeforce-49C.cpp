/*************************************************************************
	> File Name: codeforce-49C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月18日 星期六 23时00分28秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 4e6 + 10;

int a[maxn];
int num[10005];

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		memset(num, 0, sizeof num);
		scanf("%d", &n);
		int t = 0;
		for(int i = 1; i <= n; ++i){
			int x;
			scanf("%d", &x);
			num[x]++;
			if(num[x] % 2 == 0)
				a[t++] = x;
		}
		sort(a,a+t);
		double ans = 1e18;
		int x,y;
		for(int i = 1; i < t; ++i){
			double tt = 4.0*(a[i]+a[i-1])*(a[i]+a[i-1])/(a[i]*a[i-1]);
			if(tt < ans){
				ans = tt;
				x = a[i];
				y = a[i-1];
			}
		}printf("%d %d %d %d\n",x,x,y,y);
	}
	return 0;
}
