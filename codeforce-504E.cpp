/*************************************************************************
	> File Name: codeforce-504E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月18日 星期六 00时12分41秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4;

char ans[maxn], op[10];

int main(){
	int n;
	scanf("%d", &n);
	int sx = 1,sy = 1,ex = n,ey = n;
	for(int i = 0; i < n-1; ++i){
		printf("? %d %d %d %d\n",sx+1,sy,ex,ey);
		fflush(stdout);
		scanf("%s", op);
		if(op[0] == 'Y'){
			sx++;
			ans[i] = 'D';
		}else sy++,ans[i] = 'R';
	}sx = 1,sy = 1;
	for(int i = 2*n-3;i>=n-1; --i){
		printf("? %d %d %d %d\n",sx,sy,ex,ey-1);
		fflush(stdout);
		scanf("%s", op);
		if(op[0] == 'Y'){
			ey--;
			ans[i] = 'R';
		}else ex--,ans[i] = 'D';
	}
	ans[2*n-2] = '\0';
	printf("! %s\n",ans);
	fflush(stdout);
	return 0;
}
