/*************************************************************************
	> File Name: Hello-2019-A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2019年01月04日 星期五 22时20分37秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int maxn = 1e5+10;

char ss[10],s[10];

int main(){
	scanf(" %s", ss);
	bool check = false;
	for(int i = 0; i < 5; ++i){
		scanf(" %s", s);
		if(ss[0] == s[0] || ss[1] == s[1])
			check = true;
	}if(check) puts("YES");
	else puts("NO");
	return 0;
}
