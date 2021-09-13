/*************************************************************************
	> File Name: codeforce-51A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年09月20日 星期四 22时29分25秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

char s[1000], ans[1000], tmp[1000];

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf(" %s", s);
		int len = strlen(s);
		strcpy(tmp, s);
		int a=0,b=0,c=0,aa,bb,cc;
		for(int i = 0; i < len; ++i){
			if(s[i] >= 'a' && s[i] <= 'z')
				a++;
			else if(s[i] >= 'A' && s[i] <= 'Z')
				b++;
			else c++;
		}aa = a,bb = b,cc=c;
		int maxi = len;
		int l = len, r = 0;
		for(int j = 0; j < len; ++j){
			strcpy(s, tmp);
			a = aa,b = bb,c = cc;
		if(a == 0){
			for(int i = j; i < len; ++i){
				if(s[i] >= 'A' && s[i] <= 'Z' && b > 1){
					s[i] = 'a';
					b--;
					a++;
					l = min(l, i);
					r = max(r, i);
					break;
				}
				if(s[i] >= '0' && s[i] <= '9' && c > 1){
					s[i] = 'a';
					c--;
					a++;
					l = min(l,i);
					r = max(r,i);
					break;
				}
			}
		}
		if(b == 0){
			for(int i = j; i < len; ++i){
				if(s[i] >= 'a' && s[i] <= 'z' && a > 1){
					s[i] = 'A';
					a--;
					b++;
					l = min(l,i);
					r = max(r, i);
					break;
				}
				if(s[i] >= '0' && s[i] <= '9' && c > 1){
					s[i] = 'A';
					c--;
					b++;
					l = min(l, i);
					r = max(r, i);
					break;
				}
			}
		}
		if(c == 0){
			for(int i = j; i < len; ++i){
				if(s[i] >= 'A' && s[i] <= 'Z' && b > 1){
					s[i] = '1';
					b--;
					c++;
					l = min(l, i);
					r = max(r, i);
					break;
				}
				if(s[i] >= 'a' && s[i] <= 'z' && a > 1){
					s[i] = '1';
					a--;
					l = min(l, i);
					r = max(r, i);
					c++;
					break;
				}
			}
		}
		if(a&&b&&c && r - l < maxi) strcpy(ans,s);
		}
		printf("%s\n", ans);
	}
	return 0;
}
