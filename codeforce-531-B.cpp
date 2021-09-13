/*************************************************************************
	> File Name: codeforce-531-B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2019年01月09日 星期三 22时55分31秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 10;
int num[maxn];
int vis[maxn];
int a[maxn];
int ans[maxn];

int main(){
	int n,k;
	cin >> n >> k;
	bool check = true;
	int t = 0;
	for(int i = 1; i <=n; ++i){
		cin >> a[i];
		num[a[i]]++;
		if(num[a[i]] > k) check = false;
	}
	if(!check){
		puts("NO");
		return 0;
	}
	t = 1;
	puts("YES");
	for(int i = 1; i <= n; ++i)if(!vis[a[i]]){
		ans[i] = t++;
		vis[a[i]] = 1;
		if(t > k) t = 1;
		for(int j = i+1; j <= n; ++j)
			if(a[i] == a[j]){
				ans[j] = t++;
				if(t > k) t = 1;
			}
	}for(int i = 1; i <= n; ++i)
	printf("%d ", ans[i]);
	return 0;
}
