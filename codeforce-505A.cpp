/*************************************************************************
	> File Name: codeforce-505A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月19日 星期日 21时07分02秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
char s[maxn];

int num[30];

int main(){
	int n;
	scanf("%d %s", &n,s);
	bool check = false;
	for(int i = 0; i < n; ++i){
		num[s[i]-'a']++;
		if(num[s[i]-'a'] > 1) check = true;
	}
	if(n == 1 || check) puts("YES");
	else puts("NO");
	return 0;
}
