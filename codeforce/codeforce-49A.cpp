/*************************************************************************
	> File Name: codeforce-49A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月18日 星期六 22时31分29秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

char s[110];

bool check(char a, char b){
	bool ch = false;
	if(a-'a' > 0){
		if(b-'a' > 0)
			if(a-'a'-1 == b - 'a' - 1)
				ch = true;
		if(a-'a'-1 == b-'a' + 1)
			ch = true;
	}if(a-'a'+1 == b-'a' + 1) ch = true;
	if(b-'a' > 0)if(a-'a'+1 == b-'a'-1) ch = true;
	return ch == false;
}

int main(){
	int n,t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf(" %s", s);
		bool acheck = true;
		for(int i = 0; i < n/2; ++i){
			if(check(s[i],s[n-i-1]))
				acheck = false;
		}
		if(acheck) puts("YES");
		else puts("NO");
	}
	return 0;
}
