/*************************************************************************
	> File Name: LightOj-1395.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月23日 星期四 16时48分27秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100+10;

double dp[maxn];

int main(){
	int t,kase = 0;
	scanf("%d", &t);
	while(t--){
		int n,k;
		int num1 = 0, num2 = 0;
		double sum1 = 0,sum2 = 0;
		scanf("%d%d", &n,&k);
		for(int i = 1,x; i <= n; ++i){
			scanf("%d", &x);
			if(x > 0)
				sum1 += x, num1++;
			else sum2 -= x, num2++;
		}
		printf("Case %d: ", ++kase);
		if(num2 == n){
			puts("-1");
			continue;
		}if(k >= num2){
			k = num2;
			dp[k] = sum1/num1;
		}else dp[k] = (sum1/(n-k) + (num2-k) * sum2/num2/(n-k))/(1-(num2-k)*1.0/(n-k));
		for(int i = k-1; i >= 0; --i)
			dp[i] = sum1/(n-i) +(num2-i)*(dp[i+1] + sum2/num2)/(n-i);
		printf("%f\n",dp[0]);
	}return 0;
}
