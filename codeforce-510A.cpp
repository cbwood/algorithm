/*************************************************************************
	> File Name: codeforce-510A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年09月17日 星期一 15时58分47秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	int ans1 = 0,ans2 = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		ans2 = max(ans2, x);
		ans1 += x;
	}
	printf("%d %d\n",(int) ceil(1.0*(ans1+m)/n), ans2+m);
	return 0;
}
