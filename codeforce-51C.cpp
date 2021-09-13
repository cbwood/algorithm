/*************************************************************************
	> File Name: codeforce-51C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年09月20日 星期四 23时09分43秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;


int a[1000];
int b[1000];
char ans[1000];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &b[i]);
		a[b[i]]++;
	}
	int num1 = 0, num = 0;
	for(int i = 1; i <= 100; ++i){
		if(a[i] == 1) num1++;
		if(a[i] > 2) num++;
	}
	if(!(num1&1)){
		puts("YES");
		for(int i = 1; i <= n; ++i)
			if(a[b[i]] == 1){
				if(num1&1) putchar('B');
				else putchar('A');
				num1--;
			}else putchar('B');
	}else if(num > 0){
		int st = 0;
		puts("YES");
		for(int i = 1; i <= n; ++i)
			if(a[b[i]] > 2){
				st = i;
				break;
			}
		for(int i = 1; i <= n; ++i){
			if(a[b[i]] == 1){
				if(num1&1) putchar('A');
				else putchar('B');
				num1--;
			}else{
				if(i == st) putchar('B');
				else putchar('A');
			}
		}
	}else puts("NO");
}
