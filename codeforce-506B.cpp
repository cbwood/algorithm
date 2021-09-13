/*************************************************************************
	> File Name: codeforce-506B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月24日 星期五 23时09分51秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn =2e5 + 10;

int a[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i)
		scanf("%d",a+i);
	int num = 1;
	int ans = 1;
	int pre = a[1];
	for(int i = 2; i <= n; ++i)
		if(pre*2 >= a[i] ){
			num ++;
			pre = a[i];
		}else {
			ans = max(ans, num);
			num = 1;
			pre = a[i];
		}
	ans = max(ans, num);
	printf("%d\n", ans);
	return 0;
}
