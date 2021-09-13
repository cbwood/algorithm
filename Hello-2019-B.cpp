/*************************************************************************
	> File Name: Hello-2019-B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2019年01月04日 星期五 22时49分54秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int mod = 360;

int a[20];
int n;

bool dfs(int k, int sum){
	if(k == n+1){
		if(sum == 0) return true;
		return false;
	}
	if(dfs(k+1,(sum+a[k])%mod)) return true;
	return dfs(k+1,(sum-a[k]+mod)%mod);
}
int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	if(dfs(1, 0)) puts("YES");
	else puts("NO");
	return 0;
}
