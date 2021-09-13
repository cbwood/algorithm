/*************************************************************************
	> File Name: codeforce-505C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月19日 星期日 22时20分57秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

char s[maxn];

int main(){
	scanf("%s", s);
	int len = strlen(s);
	for(int i = 0; i < len-1; ++i)
		if(s[i] == s[i+1]){
			reverse(s,s+i+1);
			reverse(s+i+1,s+len);
			break;
		}
	int ans = 0;
	int sum = 1;
	for(int i = 1; i < len; ++i){
		if(s[i] == s[i-1]){
			ans = max(ans, sum);
			sum = 0;
		}sum++;
	}ans = max(ans, sum);
	printf("%d\n",ans);

}
