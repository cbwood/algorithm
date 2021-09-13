/*************************************************************************
	> File Name: codeforce-51B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年09月20日 星期四 23时04分42秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main(){
	long long  l,r;
	scanf("%lld%lld",&l,&r);
	puts("YES");
	for(long long  i = l; i < r; i += 2)
		printf("%lld %lld\n", i, i+1);
	return 0;
}
