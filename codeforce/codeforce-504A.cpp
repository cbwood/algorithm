/*************************************************************************
	> File Name: codeforce-504A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月17日 星期五 22时33分07秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;

char s[maxn],t[maxn];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	scanf(" %s %s",s,t);
	if(strcmp(s,t) == 0){
		puts("YES");
		return 0;
	}
	int l = 0;
	while(s[l] == t[l] && l < min(n,m)) l++;
	int r1 = n-1, r2 = m-1;
	while(s[r1] == t[r2] && r1 >= l && r2 >= l)r1--,r2--;
	if(l == r1 && s[l] == '*')puts("YES");
	else puts("NO");
	return 0;
}
