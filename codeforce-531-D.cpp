/*************************************************************************
	> File Name: codeforce-531-D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2019年01月09日 星期三 23时20分26秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
char s[maxn];

int main(){
	int n;
	scanf("%d %s", &n,s);
	int a=0,b=0,c=0,d=n/3;
	for(int i = 0; i < n; ++i){
		if(s[i] == '0') a++;
		if(s[i] == '1') b++;
		if(s[i] == '2') c++;
	}if(a == b && b == c){
		printf("%s\n", s);
		return 0;}
	if(a < d)
		for(int i = 0; i < n; ++i){
			if(s[i] == '2' && c > d) s[i] = '0',c--,a++;
			if(s[i] == '1' && b > d) s[i] = '0',b--,a++;
			if(a == d) break;
		}
	if(a > d)
		for(int i = n-1; i >= 0; --i){
			if(s[i] == '0' && c < d) s[i] = '2',c++,a--;
			if(a == d) break;
		}
	if(a > d)
		for(int i = n-1; i >= 0; --i){
			if(s[i] == '0' && b < d) s[i] = '1', b++,a--;
			if(a == d) break;
		}
	if(c < d)
		for(int i = n-1; i >= 0; --i){
			if(s[i] == '0' && a > d) s[i] = '2',a--,c++;
			if(s[i] == '1' && b > d) s[i] = '2',b--,c++;
			if(c == d) break;
		}
	if(c > d)
		for(int i = 0; i < n; ++i){
			if(s[i] == '2' && a < d) s[i] = '0',a++,c--;
			if(c == d) break;
		}
	if(c > d)
		for(int i = 0; i < n; ++i){
			if(s[i] == '2' && b < d) s[i] = '1', b++,c--;
			if(c == d) break;
		}
	printf("%s\n", s);
}
