/*************************************************************************
	> File Name: codeforce-504C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月17日 星期五 22时55分13秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

char s[maxn];
char ans[maxn];

bool vis[maxn];

int main(){
	int n, k;
	scanf("%d%d", &n,&k);
	scanf(" %s", s);
	int num = 0;
	int l = 0;
	int len;
	for(int i = 0; i < n; ++i){
		ans[i] = s[i];
		if(s[i] == '(')
			l++;
		else l--,num++;
		len = i;
		if(num*2 == k) break;
	}
	for(int i = len; i >= 0; i--){
		if(ans[i] == '(') vis[i] = 1,l--;
		if(l == 0) break;
	}
	for(int i = 0; i <= len; ++i)
		if(!vis[i]) putchar(ans[i]);
	return 0;
}
