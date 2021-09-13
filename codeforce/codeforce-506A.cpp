/*************************************************************************
	> File Name: codeforce-506A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月24日 星期五 22时46分01秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+ 10;
char s[maxn];
char ans[maxn];

int main(){
	int n,k;
	scanf("%d%d", &n,&k);
	scanf("%s", s);
	int t = 0;
	for(int i = 1; i < n; ++i){
		bool check = true;
		for(int j = 0; j+i < n; ++j)
			if(s[j+i] != s[j])
				check = false;
		if(check){
			t = n-i;
			break;
		}
	}
	printf("%s",s);
	for(int i = 1; i < k; ++i)
		for(int j = t; j < n; ++j)
			printf("%c",s[j]);
	return 0;
}
